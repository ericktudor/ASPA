#ifndef PROTOCOLAPPROVAL_H
#define PROTOCOLAPPROVAL_H

#include "protocol.h"

class ProtocolApproval : public Protocol
{
public:
    ProtocolApproval();
    void sendMessage(QString id_request,QString approval);
    void manageMessageRecived(){};
};

#endif // PROTOCOLAPPROVAL_H
