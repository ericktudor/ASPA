#ifndef PROTOCOLADDCAMPAIGN_H
#define PROTOCOLADDCAMPAIGN_H

#include "protocol.h"

class ProtocolAddCampaign : public Protocol
{
public:
    ProtocolAddCampaign();
    void sendMessage(QString day,QString month,QString year,QString Denumire,QString Locatie);
    void manageMessageRecived(){};
};

#endif // PROTOCOLADDCAMPAIGN_H
