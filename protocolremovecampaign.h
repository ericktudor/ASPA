#ifndef PROTOCOLREMOVECAMPAIGN_H
#define PROTOCOLREMOVECAMPAIGN_H

#include "protocol.h"

class ProtocolRemoveCampaign : public Protocol
{
public:
    ProtocolRemoveCampaign();
    void manageMessageRecived(){};
    void sendMessage(QString id);
};

#endif // PROTOCOLREMOVECAMPAIGN_H
