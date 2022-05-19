#include "protocolfilteranimals.h"

ProtocolFilterAnimals::ProtocolFilterAnimals()
{
this->delimiter="/";
this->message="";
this->code="11";
}

void ProtocolFilterAnimals::sendMessage(QString age, QString sex, QString location, QString size, QString species)
{
    this->message=code;
    this->message=message.append(this->delimiter);
    this->message=message.append(age);
    this->message=message.append(this->delimiter);
    this->message=message.append(sex);
    this->message=message.append(this->delimiter);
    this->message=message.append(location);
    this->message=message.append(this->delimiter);
    this->message=message.append(size);
    this->message=message.append(this->delimiter);
    this->message=message.append(species);
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}

void ProtocolFilterAnimals::manageMessageRecived()
{
    QString rcv;
    rcv=System::getInstance().connectionReceive();
    QStringList cmp;
    cmp=rcv.split("/");
    int i=0;
    int x=cmp[0].toInt();
    qDebug()<<x<<"here is x!";
    for(i=0;i<x;i=i+1){
        Animal* temp=new Animal(cmp[1+i*6],cmp[2+i*6].toInt(),cmp[3+i*6],cmp[4+i*6],cmp[5+i*6],cmp[6+i*6]);
        qDebug()<<cmp[1+i*6]<<cmp[2+i*6].toInt()<<cmp[3+i*6]<<cmp[4+i*6]<<cmp[5+i*6]<<cmp[6+i*6];
        System::getInstance().addAnimal(temp);
    }

}

void ProtocolFilterAnimals::changeCode()
{
this->code=QString::number(34);
}
