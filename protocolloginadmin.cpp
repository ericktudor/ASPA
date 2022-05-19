#include "protocolloginadmin.h"

Protocolloginadmin::Protocolloginadmin()
{
    this->message="";
    this->delimiter="/";
}

void Protocolloginadmin::sendMessage(QString username, QString password)
{
    this->message="30";
    this->message=message.append(this->delimiter);
    this->message=message.append(username);
    this->message=message.append(this->delimiter);
    this->message=message.append(password);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}
