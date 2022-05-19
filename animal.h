#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include "ianimal.h"

class Animal:public IAnimal
{
public:
    Animal(QString id,int age,QString sex,QString location,QString size,QString species);
    int getAge();
    QString getId();
    QString getSex();
    QString getLocation();
    QString getSize();
    QString getSpecies();
private:
    QString id;
    int age;
    QString  sex;
    QString location;
    QString size;
    QString species;
};

#endif // ANIMAL_H
