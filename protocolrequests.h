#ifndef PROTOCOLREQUESTS_H
#define PROTOCOLREQUESTS_H

#include "protocol.h"

class ProtocolRequests : public Protocol
{
public:
    ProtocolRequests();
    void manageMessageRecived();
    void sendMessage();
};

#endif // PROTOCOLREQUESTS_H
