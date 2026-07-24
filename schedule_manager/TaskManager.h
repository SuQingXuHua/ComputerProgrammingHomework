#ifndef TASKMANAGER_H
#define TASKMANAGER_H


#include "Task.h"
#include <QList>


class TaskManager
{

public:

    TaskManager();


    void addTask(Task task);


    void delTask(int index);


    QList<Task> showTask();



private:

    QList<Task> tasks;

};


#endif
