#include "animal.h"

Animal::Animal(QString id, int age, QString sex, QString location, QString size, QString species)
{
    this->id=id;
    this->age=age;
    this->sex=sex;
    this->size=size;
    this->location=location;
    this->species=species;
}

int Animal::getAge()
{
    return this->age;
}

QString Animal::getId()
{
    return this->id;
}

QString Animal::getSex()
{
    return this->sex;
}

QString Animal::getLocation()
{
    return this->location;
}

QString Animal::getSize()
{
    return this->size;
}

QString Animal::getSpecies()
{
    return this->species;
}
