#include "protocoladdcampaign.h"

ProtocolAddCampaign::ProtocolAddCampaign()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolAddCampaign::sendMessage(QString zi, QString month, QString year, QString Denumire, QString Locatie)
{
    this->message="39";
    this->message=message.append(this->delimiter);
    this->message=message.append(zi);
    this->message=message.append(this->delimiter);
    this->message=message.append(month);
    this->message=message.append(this->delimiter);
    this->message=message.append(year);
    this->message=message.append(this->delimiter);
    this->message=message.append(Denumire);
    this->message=message.append(this->delimiter);
    this->message=message.append(Locatie);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}

