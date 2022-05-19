#include "campaign.h"
#include "ui_campaign.h"
#include <QStringList>
#include "system.h"


Campaign::Campaign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Campaign)
{
    ui->setupUi(this);



}

Campaign::~Campaign()

{
    System::getInstance().emptyCampaigns();
    delete ui;
}

void Campaign::on_pushButton_2_clicked()
{
    qDebug()<<ui->calendarWidget->selectedDate();
    QString data=ui->calendarWidget->selectedDate().toString();
    qDebug()<<data;
    QStringList list;
    list=data.split(" ");
    QString Luna;
    if(list[1]=="May"){Luna="05";}
    else if(list[1]=="Jun"){Luna="06";}
    else if(list[1]=="Jul"){Luna="07";}
    else if(list[1]=="Aug"){Luna="08";}
    else if(list[1]=="Sep"){Luna="09";}
    else if(list[1]=="Oct"){Luna="10";}
    else if(list[1]=="Nov"){Luna="11";}
    else if(list[1]=="Dec"){Luna="12";}
    else if(list[1]=="Jan"){Luna="01";}
    else if(list[1]=="Feb"){Luna="02";}
    else if(list[1]=="Mar"){Luna="03";}
    else if(list[1]=="Apr"){Luna="04";}
    data=list[2];
    data=data.append(".");
    data=data.append(Luna);
    data=data.append(".");
    data=data.append(list[3]);
    qDebug()<<data<<" Here is data resulted";
    Campaigns* cmp=nullptr;
    int temp=System::getInstance().getVectCampaignSize();
    qDebug()<< temp;
    for(int i=0;i<System::getInstance().getVectCampaignSize();i++){
    qDebug()<<System::getInstance().getCampaign(i)->getData()<<"Here is data from System!";
        if(System::getInstance().getCampaign(i)->getData()==data){
            cmp=System::getInstance().getCampaign(i);
            ui->zi->setText(list[2]);
            ui->luna->setText(Luna);
            ui->an->setText(list[3]);
            ui->locatie->setText(System::getInstance().getCampaign(i)->getLocatie());
            ui->denumire->setText(System::getInstance().getCampaign(i)->getDenumire());
        }



    }
    if(cmp==nullptr){
        ui->zi->setText("None");
        ui->luna->setText("None");
        ui->an->setText("None");
        ui->locatie->setText("None");
        ui->denumire->setText("None");


    }



}


void Campaign::on_pushButton_clicked()
{
    close();
}

