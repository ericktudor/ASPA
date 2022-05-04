#include "protocolremovecampaign.h"

ProtocolRemoveCampaign::ProtocolRemoveCampaign()
{

}

void ProtocolRemoveCampaign::sendMessage(QString id)
{
    this->message="40";
    this->message=message.append(this->delimiter);
    this->message=message.append(id);
    System::getInstance().connectionSend(message);
}
