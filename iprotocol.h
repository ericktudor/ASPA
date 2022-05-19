#ifndef IPROTOCOL_H
#define IPROTOCOL_H
#include <QString>

class IProtocol
{
public:
    IProtocol();
    virtual void setDelimiter(QString delimiter)=0;
    virtual void manageMessageRecived()=0;
    virtual bool receivePermision()=0;

};

#endif // IPROTOCOL_H
