#include "protocolrequests.h"
#include "request.h"

ProtocolRequests::ProtocolRequests()
{
this->message="";
    this->delimiter="/";
}

void ProtocolRequests::manageMessageRecived()
{
    QString rcv;
    rcv=System::getInstance().connectionReceive();
    QStringList data;
    data=rcv.split("/");
    int i;
    int x=data[0].toInt();
    for(i=0;i<x;i=i+13){
        Request* temp=new Request(data[1+i],data[2+i],data[3+i],data[4+i],data[5+i],data[6+i],data[7+i],data[8+i].toInt(),data[9+i].toInt(),data[10+i].toInt(),data[11+i].toInt(),data[12+i].toInt(),data[13+1].toInt());
        System::getInstance().addRequest(temp);
        qDebug()<<data[1+i]<<data[2+i]<<data[3+i]<<data[4+i]<<data[5+i]<<data[6+i]<<data[7+i]<<data[8+i].toInt()<<data[9+i].toInt()<<data[10+i].toInt()<<data[11+i].toInt()<<data[12+i].toInt()<<data[13+1].toInt();
    }
}

void ProtocolRequests::sendMessage()
{
    this->message="32";
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}
