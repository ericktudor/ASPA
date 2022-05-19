#ifndef IEXCEPTION_H
#define IEXCEPTION_H

#include <QObject>

class IException
{
public:
    IException();
    virtual QString getMessage()=0;
    virtual QString getError_Code()=0;
};

#endif // IEXCEPTION_H
