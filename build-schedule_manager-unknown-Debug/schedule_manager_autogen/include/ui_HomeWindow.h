/********************************************************************************
** Form generated from reading UI file 'HomeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QLabel *welcomeLabel;
    QPushButton *taskButton;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QString::fromUtf8("HomeWindow"));
        HomeWindow->resize(400, 300);
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(50, 10, 300, 44));
        QFont font;
        font.setPointSize(18);
        welcomeLabel->setFont(font);
        taskButton = new QPushButton(centralwidget);
        taskButton->setObjectName(QString::fromUtf8("taskButton"));
        taskButton->setGeometry(QRect(160, 100, 81, 36));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 170, 81, 36));
        HomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HomeWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 32));
        HomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HomeWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HomeWindow->setStatusBar(statusbar);

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "MainWindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("HomeWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\346\227\245\347\250\213\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        taskButton->setText(QCoreApplication::translate("HomeWindow", "\344\273\273\345\212\241\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("HomeWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
