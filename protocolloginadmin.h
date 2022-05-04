#ifndef PROTOCOLLOGINADMIN_H
#define PROTOCOLLOGINADMIN_H

#include "protocol.h"

class Protocolloginadmin : public Protocol
{
public:
    Protocolloginadmin();
    void sendMessage(QString username,QString password);
    void manageMessageRecived(){};

};

#endif // PROTOCOLLOGINADMIN_H
