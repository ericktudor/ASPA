#include "protocolapproval.h"


ProtocolApproval::ProtocolApproval(QString approval)
{
    this->message=approval;
    this->delimiter="/";
}

void ProtocolApproval::sendMessage(QString id_request)
{
    this->message=this->message.append(delimiter);
    this->message=this->message.append(id_request);
    this->message=this->message.append(delimiter);
    System::getInstance().connectionSend(message);
}
