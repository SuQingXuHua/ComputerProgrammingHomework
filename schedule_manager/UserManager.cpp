#include "UserManager.h"

#include <QCryptographicHash>
#include <QFile>
#include <QTextStream>

UserManager::UserManager()
{
    loadUsers();
}

QString UserManager::hashPassword(QString password)
{

    QByteArray hash;


    hash = QCryptographicHash::hash(
                password.toUtf8(),
                QCryptographicHash::Sha256
                );


    return hash.toHex();

}

void UserManager::saveUsers()
{

    QFile file("data/users.txt");


    if(file.open(QIODevice::WriteOnly))
    {

        QTextStream out(&file);


        for(User user: users)
        {

            out << user.getName()
                << " "
                << user.getPasswordHash()
                << "\n";

        }


        file.close();

    }

}

void UserManager::loadUsers()
{

    QFile file("data/users.txt");


    if(file.open(QIODevice::ReadOnly))
    {

        QTextStream in(&file);


        while(!in.atEnd())
        {

            QString name;
            QString hash;


            in >> name >> hash;


            if(name!="")
            {
                users.append(
                    User(name,hash)
                );
            }

        }


        file.close();

    }

}

bool UserManager::registerUser(QString username,QString password)
{

    for(User user:users)
    {
        if(user.getName()==username)
        {
            return false;
        }
    }


    QString hash=hashPassword(password);


    users.append(
        User(username,hash)
    );


    saveUsers();


    return true;

}

bool UserManager::login(QString username,QString password)
{

    QString hash=hashPassword(password);


    for(User user:users)
    {

        if(user.getName()==username && user.getPasswordHash()==hash)
        {
            return true;
        }

    }


    return false;

}
