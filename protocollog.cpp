#include "protocollog.h"

ProtocolLog::ProtocolLog()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolLog::sendMessage()
{
    this->message="31";
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}

void ProtocolLog::manageMessageRecived()
{
    QString rcv;
    rcv=System::getInstance().connectionReceive();
    System::getInstance().setLogFile(rcv);
}
