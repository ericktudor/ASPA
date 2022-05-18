#include "protocolapproval.h"


ProtocolApproval::ProtocolApproval()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolApproval::sendMessage(QString id_request,QString approval)
{
    this->message="33";
    this->message=this->message.append(delimiter);
    this->message=this->message.append(id_request);
    this->message=this->message.append(delimiter);
    this->message=this->message.append(approval);
    this->message=this->message.append(delimiter);

    System::getInstance().connectionSend(message);
}
