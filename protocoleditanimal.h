#ifndef PROTOCOLEDITANIMAL_H
#define PROTOCOLEDITANIMAL_H

#include "protocol.h"

class ProtocolEditAnimal : public Protocol
{
public:
    ProtocolEditAnimal();
    void sendMessage(QString id_Animal,QString parametru,QString modified);
    void manageMessageRecived(){};
};

#endif // PROTOCOLEDITANIMAL_H
