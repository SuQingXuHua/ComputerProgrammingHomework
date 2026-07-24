#ifndef ADDTASKWINDOW_H
#define ADDTASKWINDOW_H


#include <QDialog>
#include "TaskManager.h"


namespace Ui {
class AddTaskWindow;
}


class AddTaskWindow : public QDialog
{

    Q_OBJECT


public:

    explicit AddTaskWindow(TaskManager *manager,QWidget *parent = nullptr);


    ~AddTaskWindow();


private slots:

    void on_confirmButton_clicked();


private:

    Ui::AddTaskWindow *ui;


    TaskManager *taskManager;

};


#endif
