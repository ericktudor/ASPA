#include "editpageanimals.h"
#include "ui_editpageanimals.h"
#include "protocolremoveanimal.h"
#include "protocoleditanimal.h"
#include <QMessageBox>

EditPageAnimals::EditPageAnimals(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPageAnimals)
{
    ui->setupUi(this);
    this->id=id;
    ui->ID->setText(id);
}

EditPageAnimals::~EditPageAnimals()
{
    delete ui;
}

void EditPageAnimals::on_pushButton_3_clicked()
{
    close();
}


void EditPageAnimals::on_pushButton_4_clicked()
{
    ProtocolRemoveAnimal pra;
    pra.sendMessage(this->id);
    if(pra.receivePermision()){
        QMessageBox::information(this,"Removed!","Done!");
    }
    else{
        QMessageBox::warning(this,"Not Removed!","Unexpected error!");

    }
}


void EditPageAnimals::on_pushButton_2_clicked()
{
    ProtocolEditAnimal pea;
    pea.sendMessage(this->id,ui->comboBox->currentText(),ui->lineEdit->text());
    if(pea.receivePermision()){
        QMessageBox::information(this,"Modified!","Done!");
    }
    else{
        QMessageBox::warning(this,"Modified!","Unexpected error!");

    }

}

