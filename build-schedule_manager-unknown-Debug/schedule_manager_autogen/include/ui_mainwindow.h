/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QSplitter *splitter;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QSplitter *splitter_2;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(120, 20, 151, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        titleLabel->setFont(font1);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(70, 160, 106, 30));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(210, 160, 106, 30));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(70, 60, 248, 29));
        splitter->setOrientation(Qt::Horizontal);
        usernameLabel = new QLabel(splitter);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        usernameLabel->setFont(font2);
        splitter->addWidget(usernameLabel);
        usernameEdit = new QLineEdit(splitter);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));
        splitter->addWidget(usernameEdit);
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(70, 100, 247, 29));
        splitter_2->setOrientation(Qt::Horizontal);
        passwordLabel = new QLabel(splitter_2);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setFont(font2);
        splitter_2->addWidget(passwordLabel);
        passwordEdit = new QLineEdit(splitter_2);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);
        splitter_2->addWidget(passwordEdit);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\227\245\345\270\270\347\256\241\347\220\206\347\263\273\347\273\237-\347\231\273\345\275\225", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\346\227\245\345\270\270\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "\345\257\206    \347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
