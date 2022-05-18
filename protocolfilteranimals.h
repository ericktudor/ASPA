#ifndef PROTOCOLFILTERANIMALS_H
#define PROTOCOLFILTERANIMALS_H

#include "protocol.h"

class ProtocolFilterAnimals : public Protocol
{
public:
    ProtocolFilterAnimals();
    void sendMessage(QString age,QString sex,QString location,QString size,QString species );
    void manageMessageRecived();
    void changeCode();//Swap for AdminSearch protocol
    private:
    QString code;
};

#endif // PROTOCOLFILTERANIMALS_H
