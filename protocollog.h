#ifndef PROTOCOLLOG_H
#define PROTOCOLLOG_H

#include "protocol.h"

class ProtocolLog : public Protocol
{
public:
    ProtocolLog();
    void sendMessage();
    void manageMessageRecived();
};

#endif // PROTOCOLLOG_H
