#include "addcampaign.h"
#include "ui_addcampaign.h"
#include "protocoladdcampaign.h"

AddCampaign::AddCampaign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCampaign)
{
    ui->setupUi(this);
}

AddCampaign::~AddCampaign()
{
    delete ui;
}

void AddCampaign::on_pushButton_2_clicked()
{
    close();
}


void AddCampaign::on_pushButton_clicked()
{
    QString day,month,year,location,name;
    day=ui->day->currentText();
    month=ui->month->currentText();
    year=ui->year->currentText();
    location=ui->location->text();
    name=ui->name->text();
    ProtocolAddCampaign pdc;
    pdc.sendMessage(day,month,year,name,location);
    if(pdc.receivePermision()){QMessageBox::information(this,"Done!","Done!");}
    else{QMessageBox::warning(this,"Fail!","Fail!");}


}

