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
    for(i=0;i<x;i=i+1){
        Request* temp=new Request(data[1+i*13],data[2+i*13],data[3+i*13],data[4+i*13],data[5+i*13],data[6+i*13],data[7+i*13],data[8+i*13].toInt(),data[9+i*13].toInt(),data[10+i*13].toInt(),data[11+i*13].toInt(),data[12+i*13].toInt(),data[13+i*13].toInt());
        System::getInstance().addRequest(temp);
        qDebug()<<data[1+i*13]<<data[2+i*13]<<data[3+i*13]<<data[4+i*13]<<data[5+i*13]<<data[6+i*13]<<data[7+i*13]<<data[8+i*13].toInt()<<data[9+i*13].toInt()<<data[10+i*13].toInt()<<data[11+i*13].toInt()<<data[12+i*13].toInt()<<data[13+i*13].toInt();
    }
}

void ProtocolRequests::sendMessage()
{
    this->message="32";
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}
