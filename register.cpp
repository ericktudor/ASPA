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
if(nume.length()>24||prenume.length()>24||user.length()>24||pass.length()>24||confirm.length()>24||email.length()>24||telefon.length()>24){
    QMessageBox::warning(this,"Error","Max number of characters reached!");
}
else{
if(pass==confirm){
    ProtocolRegister pr;
    pr.sendMessage(nume,prenume,user,pass,email,telefon);

    if(pr.receivePermision()){QMessageBox::information(this,"Succes","Succes!You can try to login now!");}
    else{

        QMessageBox::information(this,"Failure","Fail!Try again!");

    }
}
else{
    QMessageBox::warning(this,"Password/Confirm error","Parola si confirmarea nu se potrivesc!");

}
}

}

