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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QLabel *welcomeLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *addTaskButton;
    QPushButton *delTaskButton;
    QPushButton *showTaskButton;
    QPushButton *logoutButton;
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
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(150, 70, 83, 167));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addTaskButton = new QPushButton(widget);
        addTaskButton->setObjectName(QString::fromUtf8("addTaskButton"));

        verticalLayout->addWidget(addTaskButton);

        delTaskButton = new QPushButton(widget);
        delTaskButton->setObjectName(QString::fromUtf8("delTaskButton"));

        verticalLayout->addWidget(delTaskButton);

        showTaskButton = new QPushButton(widget);
        showTaskButton->setObjectName(QString::fromUtf8("showTaskButton"));

        verticalLayout->addWidget(showTaskButton);

        logoutButton = new QPushButton(widget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));

        verticalLayout->addWidget(logoutButton);

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
        addTaskButton->setText(QCoreApplication::translate("HomeWindow", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
        delTaskButton->setText(QCoreApplication::translate("HomeWindow", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        showTaskButton->setText(QCoreApplication::translate("HomeWindow", "\346\237\245\347\234\213\344\273\273\345\212\241", nullptr));
        logoutButton->setText(QCoreApplication::translate("HomeWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
