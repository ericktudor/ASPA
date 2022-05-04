#include "campaigns.h"


Campaigns::Campaigns(QString data, QString denumire, QString locatie)
{
    this->data=data;
    this->denumire=denumire;
    this->locatie=locatie;
}

void Campaigns::setData(QString data)
{
    this->data=data;
}

void Campaigns::setDenumire(QString denumire)
{
    this->denumire=denumire;
}

void Campaigns::setLocatie(QString locatie)
{
    this->locatie=locatie;
}

QString Campaigns::getData()
{
    return this->data;
}

QString Campaigns::getDenumire()
{
    return this->denumire;
}

QString Campaigns::getLocatie()
{
    return this->locatie;
}
