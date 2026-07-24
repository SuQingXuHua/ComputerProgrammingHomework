/********************************************************************************
** Form generated from reading UI file 'AddTaskWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASKWINDOW_H
#define UI_ADDTASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTaskWindow
{
public:
    QLineEdit *nameEdit;
    QComboBox *typecomboBox;
    QComboBox *prioritycomboBox;
    QDateTimeEdit *startTime;
    QDateTimeEdit *remindTime;
    QPushButton *confirmButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *attributeLabel;
    QLabel *priorityLabel;
    QLabel *starttimeLabel;
    QLabel *remindtimeLabel;

    void setupUi(QDialog *AddTaskWindow)
    {
        if (AddTaskWindow->objectName().isEmpty())
            AddTaskWindow->setObjectName(QString::fromUtf8("AddTaskWindow"));
        AddTaskWindow->resize(600, 450);
        nameEdit = new QLineEdit(AddTaskWindow);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(130, 60, 281, 29));
        typecomboBox = new QComboBox(AddTaskWindow);
        typecomboBox->setObjectName(QString::fromUtf8("typecomboBox"));
        typecomboBox->setGeometry(QRect(130, 120, 96, 29));
        prioritycomboBox = new QComboBox(AddTaskWindow);
        prioritycomboBox->setObjectName(QString::fromUtf8("prioritycomboBox"));
        prioritycomboBox->setGeometry(QRect(130, 190, 96, 29));
        startTime = new QDateTimeEdit(AddTaskWindow);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setGeometry(QRect(130, 250, 212, 30));
        remindTime = new QDateTimeEdit(AddTaskWindow);
        remindTime->setObjectName(QString::fromUtf8("remindTime"));
        remindTime->setGeometry(QRect(130, 320, 212, 30));
        confirmButton = new QPushButton(AddTaskWindow);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(440, 320, 106, 30));
        widget = new QWidget(AddTaskWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 40, 92, 321));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        verticalLayout->addWidget(nameLabel);

        attributeLabel = new QLabel(widget);
        attributeLabel->setObjectName(QString::fromUtf8("attributeLabel"));

        verticalLayout->addWidget(attributeLabel);

        priorityLabel = new QLabel(widget);
        priorityLabel->setObjectName(QString::fromUtf8("priorityLabel"));

        verticalLayout->addWidget(priorityLabel);

        starttimeLabel = new QLabel(widget);
        starttimeLabel->setObjectName(QString::fromUtf8("starttimeLabel"));

        verticalLayout->addWidget(starttimeLabel);

        remindtimeLabel = new QLabel(widget);
        remindtimeLabel->setObjectName(QString::fromUtf8("remindtimeLabel"));

        verticalLayout->addWidget(remindtimeLabel);


        retranslateUi(AddTaskWindow);

        QMetaObject::connectSlotsByName(AddTaskWindow);
    } // setupUi

    void retranslateUi(QDialog *AddTaskWindow)
    {
        AddTaskWindow->setWindowTitle(QCoreApplication::translate("AddTaskWindow", "Dialog", nullptr));
        confirmButton->setText(QCoreApplication::translate("AddTaskWindow", "\347\241\256\350\256\244", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddTaskWindow", "\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        attributeLabel->setText(QCoreApplication::translate("AddTaskWindow", "\344\273\273\345\212\241\345\261\236\346\200\247\357\274\232", nullptr));
        priorityLabel->setText(QCoreApplication::translate("AddTaskWindow", "\344\274\230  \345\205\210  \347\272\247\357\274\232", nullptr));
        starttimeLabel->setText(QCoreApplication::translate("AddTaskWindow", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        remindtimeLabel->setText(QCoreApplication::translate("AddTaskWindow", "\346\217\220\351\206\222\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTaskWindow: public Ui_AddTaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASKWINDOW_H
