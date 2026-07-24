#include "TaskManager.h"
#include <QFile>
#include <QTextStream>



TaskManager::TaskManager(QString username)
{

    this->username=username;

    loadTasks();

}

int TaskManager::getNewID()
{

    int maxID=0;


    for(Task task:tasks)
    {

        if(task.getID()>maxID)
        {
            maxID=task.getID();
        }

    }


    return maxID+1;

}



void TaskManager::addTask(Task task)
{

    tasks.append(task);
    saveTasks();

}



void TaskManager::delTask(int id)
{

    for(int i=0;i<tasks.size();i++)
    {

        if(tasks[i].getID()==id)
        {

            tasks.removeAt(i);

            saveTasks();

            return;

        }

    }

}



QList<Task> TaskManager::showTask()
{

    return tasks;

}

QString TaskManager::getFileName()
{

    return username + "_tasks.txt";

}

void TaskManager::saveTasks()
{

    QFile file(getFileName());


    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream out(&file);


        for(Task task : tasks)
        {

            out << task.getID()<< " "
                << task.getName()<< " "
                << task.getType()<< " "
                << task.getPriority()<< " "
                << task.getStartTime()<< " "
                << task.getRemindTime()<< "\n";

        }


        file.close();

    }

}

void TaskManager::loadTasks()
{

    QFile file(getFileName());


    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream in(&file);


        while(!in.atEnd())
        {

            int id;
            QString name;
            QString type;
            QString priority;
            QString start;
            QString remind;

            in >> id >> name >> type >> priority >> start >> remind;


            if(name!="")
            {

                tasks.append(
                    Task(id,name,type,priority,start,remind)
                );

            }

        }


        file.close();

    }

}
