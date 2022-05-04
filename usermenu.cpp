#include "usermenu.h"
#include "ui_usermenu.h"
#include "eventreport.h"
#include "campaign.h"
#include "informationsmenu.h"
#include "system.h"
#include "protocolcampaigns.h"

UserMenu::UserMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserMenu)
{
    ui->setupUi(this);
    ui->label_2->setText(System::getInstance().getUsername());

}

UserMenu::~UserMenu()
{
    delete ui;
}

void UserMenu::on_pushButton_clicked()
{
FilterAdopt fil;
fil.setModal(true);
fil.exec();
//hide();
}


void UserMenu::on_pushButton_3_clicked()
{
InformationsMenu info;
info.setModal(true);
info.exec();
}


void UserMenu::on_pushButton_4_clicked()
{
    EventReport event;
    event.setModal(true);
    event.exec();
    //hide();

}


void UserMenu::on_pushButton_2_clicked()
{
ProtocolCampaigns pc;
pc.sendMessage();
pc.manageMessageRecived();
Campaign c;
c.setModal(true);
c.exec();
//hide();
}


void UserMenu::on_pushButton_5_clicked()
{
    close();
}

