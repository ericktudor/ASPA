#include "adoptformular.h"
#include "ui_adoptformular.h"
#include "protocolformular.h"


AdoptFormular::AdoptFormular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdoptFormular)
{
    ui->setupUi(this);
}

AdoptFormular::~AdoptFormular()
{
    delete ui;
}

void AdoptFormular::on_pushButton_2_clicked()
{
    ProtocolFormular frm;
    frm.sendMessage(System::getInstance().getUsername(),ui->R1->isChecked(),ui->R2->isChecked(),ui->R3->isChecked(),ui->R4->isChecked(),ui->R5->isChecked(),ui->R6->isChecked());
    if(frm.receivePermision()){
        QMessageBox::information(this,"Succes!","Done!");
        close();
    }
    else{
        QMessageBox::warning(this,"Fail!","Unexpected error!");
    }
}


void AdoptFormular::on_pushButton_clicked()
{
    close();
}

