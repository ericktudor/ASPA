#ifndef REQUEST_H
#define REQUEST_H
#include <QString>

class Request
{
public:
    Request(QString Id_Req,QString Name,QString Surname,QString Telephone,QString Email,QString Id_User,QString Id_Animal,bool R1,bool R2,bool R3,bool R4,bool R5,bool R6);
    QString getId_Req();
    QString getName();
    QString getSurname();
    QString getTelephone();
    QString getEmail();
    QString getId_User();
    QString getId_Animal();
    bool getR1();
    bool getR2();
    bool getR3();
    bool getR4();
    bool getR5();
    bool getR6();
private:
    QString Id_Req;
    QString Name;
    QString Surname;
    QString Telephone;
    QString Email;
    QString Id_User;
    QString Id_Animal;
    bool R1;
    bool R2;
    bool R3;
    bool R4;
    bool R5;
    bool R6;
};

#endif // REQUEST_H
