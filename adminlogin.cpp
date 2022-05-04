#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "adminmenu.h"
#include "protocolloginadmin.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_pushButton_2_clicked()
{
    close();
}


void AdminLogin::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    Protocolloginadmin l;
    l.sendMessage(user,password);
       if(l.receivePermision()){
           AdminMenu adm;
           adm.setModal(true);
           hide();
           adm.exec();}




//    QString msg;
//    msg="30/"+user+"/"+password+"/";
//    System::getInstance().connectionSend(msg);
//   QString rcv= System::getInstance().connectionReceive();
//   if(rcv[1]=='1'){
//       AdminMenu adm;
//       adm.setModal(true);
//       hide();
//       adm.exec();
//}
   // if((user=="admin")&&(password=="admin")){
     //  AdminMenu adm;
    //   adm.setModal(true);
    //   hide();
//       adm.exec();

  //  }
}

