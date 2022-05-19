#include "protocolremoveanimal.h"

ProtocolRemoveAnimal::ProtocolRemoveAnimal()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolRemoveAnimal::sendMessage(QString id)
{
    this->message="38";
    this->message=message.append(this->delimiter);
    this->message=message.append(id);
    System::getInstance().connectionSend(message);
}
