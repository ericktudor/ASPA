#ifndef PROTOCOLREMOVEANIMAL_H
#define PROTOCOLREMOVEANIMAL_H

#include "protocol.h"

class ProtocolRemoveAnimal : public Protocol
{
public:
    ProtocolRemoveAnimal();
    void manageMessageRecived(){};
    void sendMessage(QString id);
};

#endif // PROTOCOLREMOVEANIMAL_H
