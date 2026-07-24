#include "TaskManager.h"



TaskManager::TaskManager()
{

}



void TaskManager::addTask(Task task)
{

    tasks.append(task);

}



void TaskManager::delTask(int index)
{

    if(index>=0 && index<tasks.size())
    {
        tasks.removeAt(index);
    }

}



QList<Task> TaskManager::showTask()
{

    return tasks;

}
