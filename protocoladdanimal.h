#ifndef PROTOCOLADDANIMAL_H
#define PROTOCOLADDANIMAL_H

#include "protocol.h"

class ProtocolAddAnimal : public Protocol
{
public:
    ProtocolAddAnimal();
    void sendMessage(QString age,QString sex,QString location,QString size,QString species );
    void manageMessageRecived(){};

};

#endif // PROTOCOLADDANIMAL_H
