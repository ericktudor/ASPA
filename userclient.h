#ifndef USERCLIENT_H
#define USERCLIENT_H

#include "iuser.h"

class UserClient : public IUser
{
private:
    QString user;
    QString id;
public:
    explicit UserClient(QObject *parent = nullptr);
    void setUser(QString username);
    void setId(QString id);
    QString getId();
    QString getUser();
};

#endif // USERCLIENT_H
