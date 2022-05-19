#ifndef PROTOCOLFORMULAR_H
#define PROTOCOLFORMULAR_H

#include "protocol.h"

class ProtocolFormular : public Protocol
{
public:
    ProtocolFormular();
    void sendMessage(QString IdUser,bool R1,bool R2 , bool R3,bool R4,bool R5,bool R6 );
    void manageMessageRecived(){};
};

#endif // PROTOCOLFORMULAR_H
