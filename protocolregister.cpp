#include "protocolregister.h"

ProtocolRegister::ProtocolRegister()
{
this->message="";
    this->delimiter="/";
}

void ProtocolRegister::manageMessageRecived()
{
}

void ProtocolRegister::sendMessage(QString name, QString surname, QString user, QString password, QString email, QString telephone)
{
    this->message="20";
    this->message=message.append(this->delimiter);
    this->message=message.append(name);
    this->message=message.append(this->delimiter);
    this->message=message.append(surname);
    this->message=message.append(this->delimiter);
    this->message=message.append(user);
    this->message=message.append(this->delimiter);
    this->message=message.append(password);
    this->message=message.append(this->delimiter);
    this->message=message.append(email);
    this->message=message.append(this->delimiter);
    this->message=message.append(telephone);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}
