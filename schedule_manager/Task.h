#ifndef TASK_H
#define TASK_H

#include <QString>


class Task
{

public:

    Task();


    Task(QString name,QString type,QString startTime,QString remindTime);


    QString getName();

    QString getType();

    QString getStartTime();

    QString getRemindTime();


private:

    QString name;

    QString type;

    QString startTime;

    QString remindTime;

};


#endif
