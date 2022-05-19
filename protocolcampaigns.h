#ifndef PROTOCOLCAMPAIGNS_H
#define PROTOCOLCAMPAIGNS_H

#include "protocol.h"
#include "campaigns.h"

class ProtocolCampaigns : public Protocol
{
public:
    ProtocolCampaigns();
    void sendMessage();
    void manageMessageRecived();
};

#endif // PROTOCOLCAMPAIGNS_H
