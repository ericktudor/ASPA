#ifndef PROTOCOLAPPROVAL_H
#define PROTOCOLAPPROVAL_H

#include "protocol.h"

class ProtocolApproval : public Protocol
{
public:
    ProtocolApproval(QString approval);
    void sendMessage(QString id_request);
    void manageMessageRecived(){};
};

#endif // PROTOCOLAPPROVAL_H
