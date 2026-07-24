#include "TaskManager.h"
#include <QFile>
#include <QTextStream>



TaskManager::TaskManager()
{
    loadTasks();
}



void TaskManager::addTask(Task task)
{

    tasks.append(task);
    saveTasks();

}



void TaskManager::delTask(int index)
{

    if(index>=0 && index<tasks.size())
    {
        tasks.removeAt(index);
    }
    saveTasks();

}



QList<Task> TaskManager::showTask()
{

    return tasks;

}

void TaskManager::saveTasks()
{

    QFile file("data/users.txt");


    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream out(&file);


        for(Task task : tasks)
        {

            out << task.getName() << " "
                << task.getType() << " "
                << task.getStartTime() << " "
                << task.getRemindTime() << "\n";

        }


        file.close();

    }

}

void TaskManager::loadTasks()
{

    QFile file("data/tasks.txt");


    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream in(&file);


        while(!in.atEnd())
        {

            QString name;
            QString type;
            QString start;
            QString remind;


            in >> name >> type >> start >> remind;


            if(name!="")
            {

                tasks.append(
                    Task(name,type,start,remind)
                );

            }

        }


        file.close();

    }

}
