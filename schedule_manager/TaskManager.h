#ifndef TASKMANAGER_H
#define TASKMANAGER_H


#include "Task.h"
#include <QList>
#include <QString>


class TaskManager
{

public:

    TaskManager(QString username);


    void addTask(Task task);


    void delTask(int id);


    QList<Task> showTask();

    int getNewID();



private:

    QList<Task> tasks;


    QString username;


    void saveTasks();

    void loadTasks();


    QString getFileName();


};


#endif
