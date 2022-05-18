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
    qDebug()<<x<<"Number of Campaigns";
    for(i=0;i<x;i=i+1){
        Campaigns* temp=new Campaigns(data[1+i*3],data[2+i*3],data[3+i*3]);

         qDebug()<<data[1+i*3]<<data[2+i*3]<<data[3+i*3]<<" Campaigns data";
        System::getInstance().addCampaign(temp);
    }

}
