#include "User.h"


User::User()
{

}


User::User(QString name, QString password)
{
    username = name;
    passwordHash = password;
}


QString User::getName()
{
    return username;
}


QString User::getPasswordHash()
{
    return passwordHash;
}
