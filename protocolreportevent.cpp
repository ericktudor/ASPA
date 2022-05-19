#include "protocolreportevent.h"

ProtocolReportEvent::ProtocolReportEvent()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolReportEvent::sendMessage(QString Name, QString Surname, QString Telephone, QString Locatie, QString Descriere)
{
    this->message="13";
    this->message=message.append(this->delimiter);
    this->message=message.append(Name);
    this->message=message.append(this->delimiter);
    this->message=message.append(Surname);
    this->message=message.append(this->delimiter);
    this->message=message.append(Telephone);
    this->message=message.append(this->delimiter);
    this->message=message.append(Locatie);
    this->message=message.append(this->delimiter);
    this->message=message.append(Descriere);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}
