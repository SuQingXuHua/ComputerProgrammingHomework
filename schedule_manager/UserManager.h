#ifndef USERMANAGER_H
#define USERMANAGER_H


#include "User.h"
#include <QList>


class UserManager
{

public:

    UserManager();


    bool registerUser(QString username, QString password);


    bool login(QString username, QString password);


private:

    QString hashPassword(QString password);


    QList<User> users;


    void loadUsers();

    void saveUsers();

};


#endif
