#ifndef ICAMPAIGNS_H
#define ICAMPAIGNS_H
#include <QString>

class ICampaigns
{
public:
    ICampaigns();
    virtual void setData(QString data)=0;
    virtual void setDenumire(QString denumire)=0;
    virtual void setLocatie(QString locatie)=0;
    virtual QString getData()=0;
    virtual QString getDenumire()=0;
    virtual QString getLocatie()=0;
};

#endif // ICAMPAIGNS_H
