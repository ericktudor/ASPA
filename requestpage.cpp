#include "requestpage.h"
#include "ui_requestpage.h"
#include "protocolapproval.h"
#include "QMessageBox"

RequestPage::RequestPage(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestPage)
{

    ui->setupUi(this);
    qDebug()<<System::getInstance().getVectRequestSize();
    for(int i=0;i<System::getInstance().getVectRequestSize();i++){
        if(System::getInstance().getRequest(i)->getId_Req()==id){
            qDebug()<<System::getInstance().getRequest(i)->getId_Req();

            this->req=System::getInstance().getRequest(i);
        }
        ui->Nume_X->setText(req->getName());
        ui->Prenume_X->setText(req->getSurname());
        ui->Email_X->setText(req->getEmail());
        ui->Telefon_X->setText(req->getTelephone());
        ui->Id_Animal_X->setText(req->getId_Animal());
        ui->R1->setText(QString::number(req->getR1()));
        ui->R2->setText(QString::number(req->getR2()));
        ui->R3->setText(QString::number(req->getR3()));
        ui->R4->setText(QString::number(req->getR4()));
        ui->R5->setText(QString::number(req->getR5()));
        ui->R6->setText(QString::number(req->getR6()));

    }


}

RequestPage::~RequestPage()
{
    delete ui;
}

void RequestPage::on_pushButton_clicked()
{
    ProtocolApproval pa;
    pa.sendMessage(req->getId_Req(),"1");
    if(pa.receivePermision()){QMessageBox::warning(this,"Done!","Done!");}
    else{QMessageBox::warning(this,"Not Done!","Not Done!");}
    close();
}


void RequestPage::on_pushButton_2_clicked()
{
    ProtocolApproval pa;
    pa.sendMessage(req->getId_Req(),"0");
    if(pa.receivePermision()){QMessageBox::warning(this,"Done!","Done!");}
    else{QMessageBox::warning(this,"Not Done!","Not Done!");}
    close();
}


void RequestPage::on_pushButton_3_clicked()
{
    close();
}

