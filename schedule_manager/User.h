#ifndef USER_H
#define USER_H

#include <QString>


class User
{
public:

    User();

    User(QString name, QString passwordHash);


    QString getName();

    QString getPasswordHash();


private:

    QString username;

    QString passwordHash;
};


#endif
