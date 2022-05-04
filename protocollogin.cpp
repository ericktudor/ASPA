#include "protocollogin.h"

ProtocolLogin::ProtocolLogin()
{
this->message="";
this->delimiter="/";
}

void ProtocolLogin::sendMessage(QString username, QString password)
{
    this->message="10";
    this->message=message.append(this->delimiter);
    this->message=message.append(username);
    this->message=message.append(this->delimiter);
    this->message=message.append(password);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);

}
