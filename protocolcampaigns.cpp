#include "protocolcampaigns.h"

ProtocolCampaigns::ProtocolCampaigns()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolCampaigns::sendMessage()
{
    this->message="14";
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}

void ProtocolCampaigns::manageMessageRecived()
{
    QString rcv;
    rcv=System::getInstance().connectionReceive();
    QStringList data;
    data=rcv.split("/");
    int i;
    int x=data[0].toInt();
    for(i=0;i<x;i=i+3){
        Campaigns* temp=new Campaigns(data[1+i],data[2+i],data[3+i]);
        System::getInstance().addCampaign(temp);
    }

}
