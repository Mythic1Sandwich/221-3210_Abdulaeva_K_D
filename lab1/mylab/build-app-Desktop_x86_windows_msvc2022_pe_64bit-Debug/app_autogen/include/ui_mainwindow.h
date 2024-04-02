/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QLabel *lblLogin;
    QSpacerItem *horizontalSpacer;
    QLineEdit *edtPin;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(645, 600);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(100000, 10000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setLayoutDirection(Qt::LeftToRight);
        stackedWidget->setAutoFillBackground(false);
        page = new QWidget();
        page->setObjectName("page");
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        lblLogin = new QLabel(page);
        lblLogin->setObjectName("lblLogin");

        gridLayout->addWidget(lblLogin, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        edtPin = new QLineEdit(page);
        edtPin->setObjectName("edtPin");
        edtPin->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(edtPin, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_6->addWidget(lineEdit);

        listWidget = new QListWidget(page_2);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget::item{\n"
"           background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0,\n"
"                   stop:0 rgba(218, 215, 205, 255),\n"
"                   stop:0.25 rgba(191, 191, 191, 255),\n"
"                   stop:0.5 rgba(163, 163, 163, 255),\n"
"                   stop:0.75 rgba(135, 135, 135, 255),\n"
"                   stop:1 rgba(108, 108, 108, 255));\n"
"}"));

        verticalLayout_6->addWidget(listWidget);

        stackedWidget->addWidget(page_2);

        verticalLayout_5->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblLogin->setText(QCoreApplication::translate("MainWindow", "\320\237\320\270\320\275-\320\272\320\276\320\264", nullptr));
        edtPin->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\270\320\275-\320\272\320\276\320\264", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
