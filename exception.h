#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "iexception.h"
#include <QString>

class Exception : public IException
{
public:
    Exception(QString message,int error_code);
    QString getMessage();
    QString getError_Code();
private:
    QString message;
    int error_code;
};

#endif // EXCEPTION_H
