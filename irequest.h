#ifndef IREQUEST_H
#define IREQUEST_H
#include <QString>

class IRequest
{
public:
    IRequest();
    virtual QString getId_Req()=0;
    virtual QString getName()=0;
    virtual QString getSurname()=0;
    virtual QString getTelephone()=0;
    virtual QString getEmail()=0;
    virtual QString getId_User()=0;
    virtual QString getId_Animal()=0;
    virtual bool getR1()=0;
    virtual bool getR2()=0;
    virtual bool getR3()=0;
    virtual bool getR4()=0;
    virtual bool getR5()=0;
    virtual bool getR6()=0;
};

#endif // IREQUEST_H
