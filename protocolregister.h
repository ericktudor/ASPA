#ifndef PROTOCOLREGISTER_H
#define PROTOCOLREGISTER_H

#include "protocol.h"


class ProtocolRegister : public Protocol
{
public:
    ProtocolRegister();
    void manageMessageRecived();
    void sendMessage(QString name,QString surname,QString user,QString password,QString email,QString telephone );
};

#endif // PROTOCOLREGISTER_H
