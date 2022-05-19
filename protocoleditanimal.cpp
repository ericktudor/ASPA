#include "protocoleditanimal.h"

ProtocolEditAnimal::ProtocolEditAnimal()
{
    this->message="";
    this->delimiter="/";
}

void ProtocolEditAnimal::sendMessage(QString id_Animal, QString parametru, QString modified)
{
    this->message="36";
    this->message=this->message.append(delimiter);
    QString temp;
    if(parametru=="Varsta"){temp="Age";}
    else if(parametru=="Talie"){temp="Size";}
    else if(parametru=="Specie"){temp="Species";}
    else if(parametru=="Locatie"){temp="Location";}
    else{temp="Sex";}
    this->message=this->message.append(id_Animal);
    this->message=this->message.append(delimiter);
    this->message=this->message.append(temp);
    this->message=this->message.append(delimiter);
    this->message=this->message.append(modified);
    this->message=this->message.append(delimiter);
    System::getInstance().connectionSend(message);
}
