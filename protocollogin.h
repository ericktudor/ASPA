#ifndef PROTOCOLLOGIN_H
#define PROTOCOLLOGIN_H

#include "protocol.h"

class ProtocolLogin : public Protocol
{
public:
    ProtocolLogin();
    void sendMessage(QString username,QString password);
    void manageMessageRecived(){};

};

#endif // PROTOCOLLOGIN_H
