#include "AddTaskWindow.h"
#include "ui_AddTaskWindow.h"

AddTaskWindow::AddTaskWindow(TaskManager *manager,QWidget *parent):QDialog(parent),ui(new Ui::AddTaskWindow)
{
    ui->setupUi(this);


    taskManager = manager;

}

AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}

void AddTaskWindow::on_confirmButton_clicked()
{

    QString name =
            ui->nameEdit->text();


    QString type =
            ui->typecomboBox->currentText();


    QString priority =
            ui->prioritycomboBox->currentText();


    QString start =
            ui->startTime->dateTime().toString("yyyy-MM-dd_HH:mm");


    QString remind =
            ui->remindTime->dateTime().toString("yyyy-MM-dd_HH:mm");



    Task task(taskManager->getNewID(),name,type,priority,start,remind);


    taskManager->addTask(task);


    close();

}
