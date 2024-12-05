#ifndef CAMPAIGNS_H
#define CAMPAIGNS_H

#include <QString>

class Campaigns
{
public:
    Campaigns(QString data,QString denumire,QString locatie);
    void setData(QString data);
    void setDenumire(QString denumire);
    void setLocatie(QString locatie);
    QString getData();
    QString getDenumire();
    QString getLocatie();

private:
    QString data;
    QString denumire;
    QString locatie;

};

#endif // CAMPAIGNS_H