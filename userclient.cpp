#include "userclient.h"

UserClient::UserClient(QObject *parent)
    : IUser{parent}
{

}


void UserClient::setUser(QString username)
{
    this->user=username;
}

void UserClient::setId(QString id)
{
    this->id=id;
}

QString UserClient::getId()
{
    return this->id;
}

QString UserClient::getUser()
{
    return user;
}
