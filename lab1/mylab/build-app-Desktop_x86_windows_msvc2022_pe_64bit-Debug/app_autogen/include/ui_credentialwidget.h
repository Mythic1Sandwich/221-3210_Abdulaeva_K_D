/********************************************************************************
** Form generated from reading UI file 'credentialwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDENTIALWIDGET_H
#define UI_CREDENTIALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CredentialWidget
{
public:
    QWidget *spacerItem1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lblIcon;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblSite;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblLogin;
    QLineEdit *edtLogin;
    QPushButton *btnLoginCopy;
    QLabel *lblPassword;
    QLineEdit *edtPassword;
    QPushButton *btnPassCopy;

    void setupUi(QWidget *CredentialWidget)
    {
        if (CredentialWidget->objectName().isEmpty())
            CredentialWidget->setObjectName("CredentialWidget");
        CredentialWidget->resize(1181, 247);
        spacerItem1 = new QWidget(CredentialWidget);
        spacerItem1->setObjectName("spacerItem1");
        spacerItem1->setGeometry(QRect(0, 0, 100, 30));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spacerItem1->sizePolicy().hasHeightForWidth());
        spacerItem1->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CredentialWidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lblIcon = new QLabel(CredentialWidget);
        lblIcon->setObjectName("lblIcon");
        lblIcon->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblIcon->sizePolicy().hasHeightForWidth());
        lblIcon->setSizePolicy(sizePolicy1);
        lblIcon->setMinimumSize(QSize(10, 10));
        lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/images/images/lock-custom.png")));

        verticalLayout->addWidget(lblIcon);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 4, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        gridLayout->addLayout(verticalLayout_2, 0, 7, 1, 1);

        lblSite = new QLabel(CredentialWidget);
        lblSite->setObjectName("lblSite");

        gridLayout->addWidget(lblSite, 0, 5, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lblLogin = new QLabel(CredentialWidget);
        lblLogin->setObjectName("lblLogin");
        lblLogin->setMinimumSize(QSize(100, 20));
        lblLogin->setMaximumSize(QSize(100, 20));
        lblLogin->setSizeIncrement(QSize(100, 20));

        verticalLayout_3->addWidget(lblLogin);

        edtLogin = new QLineEdit(CredentialWidget);
        edtLogin->setObjectName("edtLogin");
        edtLogin->setEchoMode(QLineEdit::Password);
        edtLogin->setReadOnly(true);

        verticalLayout_3->addWidget(edtLogin);

        btnLoginCopy = new QPushButton(CredentialWidget);
        btnLoginCopy->setObjectName("btnLoginCopy");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/content-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoginCopy->setIcon(icon);

        verticalLayout_3->addWidget(btnLoginCopy);

        lblPassword = new QLabel(CredentialWidget);
        lblPassword->setObjectName("lblPassword");
        sizePolicy1.setHeightForWidth(lblPassword->sizePolicy().hasHeightForWidth());
        lblPassword->setSizePolicy(sizePolicy1);
        lblPassword->setMaximumSize(QSize(100, 20));

        verticalLayout_3->addWidget(lblPassword);

        edtPassword = new QLineEdit(CredentialWidget);
        edtPassword->setObjectName("edtPassword");
        edtPassword->setMaxLength(32765);
        edtPassword->setEchoMode(QLineEdit::Password);
        edtPassword->setReadOnly(true);

        verticalLayout_3->addWidget(edtPassword);

        btnPassCopy = new QPushButton(CredentialWidget);
        btnPassCopy->setObjectName("btnPassCopy");
        btnPassCopy->setIcon(icon);

        verticalLayout_3->addWidget(btnPassCopy);


        gridLayout->addLayout(verticalLayout_3, 0, 6, 1, 1);


        retranslateUi(CredentialWidget);

        QMetaObject::connectSlotsByName(CredentialWidget);
    } // setupUi

    void retranslateUi(QWidget *CredentialWidget)
    {
        CredentialWidget->setWindowTitle(QCoreApplication::translate("CredentialWidget", "CredentialWidget", nullptr));
        lblSite->setText(QCoreApplication::translate("CredentialWidget", "Site Name", nullptr));
        lblLogin->setText(QCoreApplication::translate("CredentialWidget", "Login:", nullptr));
        edtLogin->setText(QCoreApplication::translate("CredentialWidget", "1232132131", nullptr));
        btnLoginCopy->setText(QCoreApplication::translate("CredentialWidget", "Login Copy", nullptr));
        lblPassword->setText(QCoreApplication::translate("CredentialWidget", "Password:", nullptr));
        edtPassword->setText(QCoreApplication::translate("CredentialWidget", "1231232132", nullptr));
        btnPassCopy->setText(QCoreApplication::translate("CredentialWidget", "Password Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CredentialWidget: public Ui_CredentialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDENTIALWIDGET_H
