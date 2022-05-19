#include "protocoladdanimal.h"

ProtocolAddAnimal::ProtocolAddAnimal()
{
this->message="";
this->delimiter="/";
}

void ProtocolAddAnimal::sendMessage(QString age, QString sex, QString location, QString size, QString species)
{

    this->message="37";
    this->message=message.append(this->delimiter);
    this->message=message.append(age);
    this->message=message.append(this->delimiter);
    this->message=message.append(sex);
    this->message=message.append(this->delimiter);
    this->message=message.append(location);
    this->message=message.append(this->delimiter);
    this->message=message.append(size);
    this->message=message.append(this->delimiter);
    this->message=message.append(species);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);

}
