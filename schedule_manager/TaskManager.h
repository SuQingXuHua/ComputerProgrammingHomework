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



private:

    QList<Task> tasks;


    QString username;


    void saveTasks();

    void loadTasks();


    QString getFileName();


    int getNewID();

};


#endif
