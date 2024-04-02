#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credentialwidget.h"
#include "QDataStream"
#include "QFile"
#include <QBuffer>
#include <evp.h>
#include <QJsonObject>
#include <QCryptographicHash>

#include <QClipboard>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Установка нового макета
    QVBoxLayout *layout = new QVBoxLayout;
    ui->centralwidget->setLayout(layout);

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::Search);

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::readJSON(QByteArray key_hex)
{
    QFile jsonFile("credentials_ecy.json");
    if (!jsonFile.open(QFile::ReadOnly)) {
        qDebug() << "Failed to open JSON file";
        return false;
    }

    QByteArray hexEncryptedBytes = jsonFile.readAll();
    jsonFile.close();

    QByteArray encryptedBytes = QByteArray::fromHex(hexEncryptedBytes);
    QByteArray decryptedBytes;
    if (decryptFile(encryptedBytes, key_hex.toHex(), decryptedBytes) != 0) {
        qDebug() << "Failed to decrypt file";
        return false;
    }


    QJsonDocument jsonDoc = QJsonDocument::fromJson(decryptedBytes);
   // qDebug() << "*** jsonDoc:" << jsonDoc;
    if(jsonDoc.isNull() || !jsonDoc.isObject()) {
        qDebug() << "Failed to parse JSON";
        return false;
    }

    QJsonObject rootObject = jsonDoc.object();
    qDebug() << "*** rootObject:" << rootObject;
    m_jsonarray = rootObject["credentials"].toArray();
     qDebug() << "*** m_jsonarray:" << m_jsonarray;
    return true;
}

void MainWindow::Search(const QString &fragment)
{
    ui->listWidget->clear();

    for (int i = 0; i < m_jsonarray.size(); i++) {
        QString site = m_jsonarray[i].toObject()["site"].toString().toLower();
        qDebug() << "*** site:" << site;
        if (site.contains(fragment.toLower()) || fragment.isEmpty()) {

            QListWidgetItem *newItem = new QListWidgetItem();
            CredentialWidget *itemWidget = new CredentialWidget(site, i);
            QObject::connect(itemWidget, &CredentialWidget::decryptLogin, this, &MainWindow::decryptLogin);
            QObject::connect(itemWidget, &CredentialWidget::decryptPassword, this, &MainWindow::decryptPassword);
            newItem->setSizeHint(itemWidget->sizeHint());
            ui->listWidget->addItem(newItem);
            ui->listWidget->setItemWidget(newItem, itemWidget);

        }
    }
}
    //IV = 461494800b7b3f2fdc1ef7528a8e6757
    // password = Canigetanamen
    //key = SHA256(password) = 825d3b1d2f1effd6633df955701f3be6fcc03f9a63a1c212af9abb7c2c24ebcd
    int MainWindow::decryptFile(
        const QByteArray & encryptedBytes, const QByteArray & key_hex,
        QByteArray & decryptedBytes
        )
    {
        QByteArray key_ba = QByteArray::fromHex(key_hex);
        // qDebug() << "*** key_ba " << key_ba;
        unsigned char key[32] = {0};
        memcpy(key, key_ba.data(), 32);
        // qDebug() << "*** key " << key;

        QByteArray iv_hex("461494800b7b3f2fdc1ef7528a8e6757");
        QByteArray iv_ba = QByteArray::fromHex(iv_hex);
        // qDebug() << "*** iv_ba " << iv_ba;
        unsigned char iv[16] = {0};
        memcpy(iv, iv_ba.data(), 16);
        // qDebug() << "*** iv " << iv;


        EVP_CIPHER_CTX *ctx;
        ctx = EVP_CIPHER_CTX_new();
        if (!EVP_DecryptInit_ex2(ctx, EVP_aes_256_cbc(), key, iv, NULL)) {
     //       qDebug() << "*** EVP_DecryptInit_ex2() ERROR";
            EVP_CIPHER_CTX_free(ctx);
            return 0;
        }
        // qDebug() << "*** EVP_DecryptInit_ex2() OK";

#define BUF_LEN 256
        unsigned char encrypted_buf[BUF_LEN] = {0}, decrypted_buf[BUF_LEN] = {0};
        int encr_len, decr_len;
        QDataStream encrypted_stream(encryptedBytes);
        decryptedBytes.clear();

        QBuffer decrypted_buffer(&decryptedBytes);
        decrypted_buffer.open(QBuffer::WriteOnly);
        encr_len = encrypted_stream.readRawData(reinterpret_cast<char*>(encrypted_buf), BUF_LEN);
        while(encr_len > 0) {
            if (!EVP_DecryptUpdate(ctx, decrypted_buf, &decr_len, encrypted_buf, encr_len)) {
                qDebug() << "*** EVP_DecryptUpdate() ERROR";
                EVP_CIPHER_CTX_free(ctx);
                return 0;
            }
            //  qDebug() << "*** DECRYPT: " << reinterpret_cast<char*>(decrypted_buf);
            decrypted_buffer.write(reinterpret_cast<char*>(decrypted_buf), decr_len);
            encr_len = encrypted_stream.readRawData(reinterpret_cast<char*>(encrypted_buf), BUF_LEN);

        }

        // qDebug() << "*** before EVP_DecryptFinal_ex" << decrypted_buffer.data();
        int tmplen;
        if (!EVP_DecryptFinal_ex(ctx, decrypted_buf, &tmplen)) {
            //   qDebug() << "*** EVP_DecryptFinal_ex() ERROR";
            EVP_CIPHER_CTX_free(ctx);
            return -1;
        }
        if (tmplen > 0) {
            decrypted_buffer.write(reinterpret_cast<char*>(decrypted_buf), tmplen);
        }
        decrypted_buffer.close();
        EVP_CIPHER_CTX_free(ctx);

        return 0;
    }

    void MainWindow::on_edtPin_returnPressed()
    {

        QByteArray hash = QCryptographicHash::hash(
            ui->edtPin->text().toUtf8(),
            QCryptographicHash::Sha256);
        qDebug() << "*** Sha256 = " << hash.toHex();
        if (m_isStartup) {
            if (readJSON(hash)) {
                ui->stackedWidget->setCurrentIndex(1);
                Search("");
                m_isStartup = false;
            } else {
                ui->lblLogin->setText("Неверный пинкод");
                ui->lblLogin->setStyleSheet("color:red;");
            }
        }
        else {
            QByteArray encrypted_creds = QByteArray::fromHex(m_jsonarray[m_current_id].toObject()["logpass"].toString().toUtf8());
            QByteArray decrypted_creds;
            decryptFile(encrypted_creds, hash.toHex(), decrypted_creds);
            qDebug() << "***decrypted_creds" << decrypted_creds;
            QString login;
            QString password;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(decrypted_creds);
            if (!jsonDoc.isNull() && jsonDoc.isObject()) {
                QJsonObject jsonObject = jsonDoc.object();
                if (jsonObject.contains("login") && jsonObject["login"].isString()) {
                    login = jsonObject["login"].toString();
                }
                if (jsonObject.contains("password") && jsonObject["password"].isString()) {
                    password = jsonObject["password"].toString();
                }
            }


            if (loginClicked) {
                QGuiApplication::clipboard()->setText(login);
            } else if (passwordClicked) {
                QGuiApplication::clipboard()->setText(password);
            }
            if(readJSON(hash)) {
                ui->stackedWidget->setCurrentIndex(1);
            }
            else {
                ui->lblLogin->setText("Неверный пинкод");
                ui->lblLogin->setStyleSheet("color:red;");
                ui->stackedWidget->setCurrentIndex(0);
            }

        }


        ui->edtPin->setText(QString().fill('*', ui->edtPin->text().size()));
        ui->edtPin->clear();
        hash.fill('*', 32);
    }



    void MainWindow::decryptLogin(int id)
    {
        m_current_id = id;
        ui->stackedWidget->setCurrentIndex(0);
        qDebug()<<m_jsonarray[id].toObject()["logpass"].toString();
        loginClicked = true;
        passwordClicked = false;
    }

    void MainWindow::decryptPassword(int id)
    {
        qDebug() << "*** decryptPassword() called with:" << m_jsonarray[id];
        m_current_id = id;
        ui->stackedWidget->setCurrentIndex(0);
        loginClicked = false;
        passwordClicked = true;
    }

    QByteArray MainWindow::showPinDialog()
    {
        ui->stackedWidget->setCurrentIndex(0);
        return QByteArray();
    }
