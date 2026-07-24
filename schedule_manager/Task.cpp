#include "Task.h"


Task::Task()
{

}


Task::Task(int id,QString name,QString type,QString priority,QString startTime,QString remindTime)
{
    this->id = id;

    this->name = name;

    this->type = type;

    this->priority = priority;

    this->startTime = startTime;

    this->remindTime = remindTime;

}



QString Task::getName()
{
    return name;
}


QString Task::getType()
{
    return type;
}


QString Task::getStartTime()
{
    return startTime;
}


QString Task::getRemindTime()
{
    return remindTime;
}

QString Task::getPriority()
{
    return priority;
}

int Task::getID()
{
    return id;
}
