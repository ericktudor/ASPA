#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "addanimal.h"
#include "addcampaign.h"
#include "manageanimals.h"
#include "logfile.h"
#include "protocollog.h"
#include "protocolrequests.h"
#include "requestslist.h"
#include "protocolremovecampaign.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_pushButton_4_clicked()
{
    AddAnimal add;
    add.setModal(true);
    add.exec();
}


void AdminMenu::on_pushButton_5_clicked()
{
    AddCampaign add;
    add.setModal(true);
    add.exec();
}


void AdminMenu::on_pushButton_3_clicked()
{
    ManageAnimals man;
    man.setModal(true);
    man.exec();
}


void AdminMenu::on_pushButton_clicked()
{
    ProtocolLog prot;
    prot.sendMessage();
    prot.manageMessageRecived();
    LogFile log;
    log.setModal(true);
    log.exec();
}


void AdminMenu::on_pushButton_2_clicked()
{
    ProtocolRequests req;
    req.sendMessage();
    req.manageMessageRecived();
    RequestsList rl;
    rl.setModal(true);
    rl.exec();
}



void AdminMenu::on_pushButton_7_clicked()
{
    ProtocolRemoveCampaign prg;
    prg.sendMessage(ui->lineEdit->text());
    if(prg.receivePermision()){
QMessageBox::warning(this,"Done!","Done!");

    }
    else{
        QMessageBox::warning(this,"Not Done!","Not Done!");
    }
}


void AdminMenu::on_pushButton_6_clicked()
{

}


void AdminMenu::on_pushButton_8_clicked()
{
    close();
}

