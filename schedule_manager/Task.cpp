#include "Task.h"


Task::Task()
{

}


Task::Task(QString name,QString type,QString startTime,QString remindTime)
{

    this->name = name;

    this->type = type;

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
