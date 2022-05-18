#ifndef PROTOCOLREPORTEVENT_H
#define PROTOCOLREPORTEVENT_H

#include "protocol.h"

class ProtocolReportEvent : public Protocol
{
public:
    ProtocolReportEvent();
    void manageMessageRecived(){};
    void sendMessage(QString Name,QString Surname,QString Telephone,QString Locatie,QString Descriere);
};

#endif // PROTOCOLREPORTEVENT_H
