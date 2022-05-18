#include "exception.h"



Exception::Exception(QString message, int error_code)
{
    this->message=message;
    this->error_code=error_code;
}

QString Exception::getMessage()
{
    return this->message;
}

QString Exception::getError_Code()
{
    QString s=QString::number(error_code);
    return s;
}
