#ifndef IANIMAL_H
#define IANIMAL_H
#include <QString>

class IAnimal
{
public:
    IAnimal();
    virtual int getAge()=0;
    virtual QString getId()=0;
    virtual QString getSex()=0;
    virtual QString getLocation()=0;
    virtual QString getSize()=0;
    virtual QString getSpecies()=0;
};

#endif // IANIMAL_H
