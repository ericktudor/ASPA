#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <protocolregister.h>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_2_clicked()
{
    close();

}


void Register::on_pushButton_clicked()
{
    QString nume;
    QString prenume;
    QString user;
    QString pass;
    QString confirm;
    QString email;
    QString telefon;
nume=ui->lineEdit->text();
prenume=ui->lineEdit_2->text();
user=ui->lineEdit_3->text();
pass=ui->lineEdit_4->text();
confirm=ui->lineEdit_5->text();
email=ui->lineEdit_6->text();
telefon=ui->lineEdit_7->text();
if(pass==confirm){
    ProtocolRegister pr;
    pr.sendMessage(nume,prenume,user,pass,email,telefon);
//    QString msg;
//    msg.append("20/");
//    msg.append(nume);
//    msg.append("/");
//    msg.append(prenume);
//    msg.append("/");
//    msg.append(user);
//    msg.append("/");
//    msg.append(pass);
//    msg.append("/");
//    msg.append(email);
//    msg.append("/");
//    msg.append(telefon);
//    msg.append("/");


//    //msg="20/"+nume+"/"+prenume+"/"+user+"/"+pass+"/"+email+"/"+telefon+"/";
//    //msg="123456789123456789123456789";
//    System::getInstance().connectionSend(msg);
//    QString rcv=System::getInstance().connectionReceive();
    if(pr.receivePermision()){QMessageBox::information(this,"Succes","Succes!You can try to login now!");}
    else{

        QMessageBox::information(this,"Failure","Fail!Try again!");

    }
}
else{
    QMessageBox::warning(this,"Password/Confirm error","Parola si confirmarea nu se potrivesc!");

}

}

