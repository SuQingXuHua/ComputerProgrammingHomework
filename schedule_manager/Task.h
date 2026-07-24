#ifndef TASK_H
#define TASK_H

#include <QString>


class Task
{

public:

    Task();


    Task(int id,QString name,QString type,QString priority,QString startTime,QString remindTime);


    QString getName();

    QString getType();

    QString getStartTime();

    QString getRemindTime();

    QString getPriority();

    int getID();

private:

    QString name;

    QString type;

    QString startTime;

    QString remindTime;

    QString priority;

    int id;

};


#endif
