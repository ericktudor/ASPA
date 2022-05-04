#include "protocolformular.h"

ProtocolFormular::ProtocolFormular()
{
    this->delimiter="/";
    this->message="";
}

void ProtocolFormular::sendMessage(QString IdUser,bool R1, bool R2, bool R3, bool R4, bool R5, bool R6)
{
    this->message="12";
    this->message=message.append(this->delimiter);
    if(R1){this->message=message.append("1");}else{this->message=message.append("0");}
    this->message=message.append(this->delimiter);
    if(R2){this->message=message.append("1");}else{this->message=message.append("0");}
    this->message=message.append(this->delimiter);
    if(R3){this->message=message.append("1");}else{this->message=message.append("0");}
    this->message=message.append(this->delimiter);
    if(R4){this->message=message.append("1");}else{this->message=message.append("0");}
    this->message=message.append(this->delimiter);
    if(R5){this->message=message.append("1");}else{this->message=message.append("0");}
    this->message=message.append(this->delimiter);
    if(R6){this->message=message.append("1");}else{this->message=message.append("0");}
    this->message=message.append(this->delimiter);
    System::getInstance().connectionSend(message);
}
