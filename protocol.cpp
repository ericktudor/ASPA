#include "protocol.h"

Protocol::Protocol()
{

}

void Protocol::setDelimiter(QString delimiter)
{
    this->delimiter=delimiter;
}

bool Protocol::receivePermision()
{
    QString rcv;
    rcv=System::getInstance().connectionReceive();
    if(rcv[1]=='1'){return 1;}
    else{return 0;}
}
