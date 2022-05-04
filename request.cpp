#include "request.h"

Request::Request(QString Id_Req, QString Name, QString Surname, QString Telephone, QString Email, QString Id_User,QString Id_Animal,bool R1, bool R2, bool R3, bool R4, bool R5, bool R6)
{
    this->Id_Req=Id_Req;
    this->Name=Name;
    this->Surname=Surname;
    this->Telephone=Telephone;
    this->Email=Email;
    this->Id_User=Id_User;
    this->Id_Animal=Id_Animal;
    this->R1=R1;
    this->R2=R2;
    this->R3=R3;
    this->R4=R4;
    this->R5=R5;
    this->R6=R6;
}

QString Request::getId_Req()
{
    return this->Id_Req;
}

QString Request::getName()
{
    return this->Name;
}

QString Request::getSurname()
{
    return this->Surname;
}

QString Request::getTelephone()
{
    return this->Telephone;
}

QString Request::getEmail()
{
    return this->Email;
}

QString Request::getId_User()
{
    return this->Id_User;
}

bool Request::getR1()
{
    return this->R1;
}

bool Request::getR2()
{
    return this->R2;
}

bool Request::getR3()
{
    return this->R3;
}

bool Request::getR4()
{
    return this->R4;
}

bool Request::getR5()
{
    return this->R5;
}

bool Request::getR6()
{
    return this->R6;
}
