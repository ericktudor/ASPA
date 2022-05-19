#include "loginuser.h"
#include "ui_loginuser.h"
#include "usermenu.h"
#include "protocollogin.h"

LoginUser::LoginUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginUser)
{
    ui->setupUi(this);
}

LoginUser::~LoginUser()
{
    delete ui;
}

void LoginUser::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if(user.length()>24||password.length()>24){
        QMessageBox::warning(this,"Error","Max number of characters reached!");
    }
    else{
    if((user!="")&& (password!="")){
        ProtocolLogin l;
        l.sendMessage(user,password);
        //client.connectToServer("127.0.0.1","54010"); //127.0.0.1//172.16.7.23
        //QString msg="10/"+user+"/"+password+"/";
        //System::getInstance().connectionSend(msg);


        //QString rcv=System::getInstance().connectionReceive();
        //if(rcv!=""){

      if(l.receivePermision()){
          System::getInstance().setUsername(user);

       UserMenu* menu;
       hide();
       menu=new UserMenu;
       menu->setModal(true);
       menu->exec();
       }
       // }


    }
    else{
        QMessageBox::warning(this,"Login Attempt","Nume sau/si parola introduse gresit!Reincercati!");
    }
    }
}


void LoginUser::on_pushButton_2_clicked()
{
    close();
}

