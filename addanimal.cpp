#include "addanimal.h"
#include "ui_addanimal.h"
#include "protocoladdanimal.h"

AddAnimal::AddAnimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAnimal)
{
    ui->setupUi(this);
}

AddAnimal::~AddAnimal()
{
    delete ui;
}

void AddAnimal::on_pushButton_clicked()
{
    ProtocolAddAnimal paa;
    paa.sendMessage(ui->varsta->text(),ui->Sex->currentText(),ui->Lcocatie->currentText(),ui->Talie->currentText(),ui->Caine->currentText());
    if(paa.receivePermision()){QMessageBox::information(this,"Succes","Succes!");}
    else{

        QMessageBox::information(this,"Failure","Fail!");

    }
}


void AddAnimal::on_pushButton_2_clicked()
{
    close();
}

