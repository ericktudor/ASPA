#include "manageanimals.h"
#include "ui_manageanimals.h"
#include "editpageanimals.h"
#include "protocolfilteranimals.h"
#include "adminanimalsearch.h"

ManageAnimals::ManageAnimals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageAnimals)
{
    ui->setupUi(this);
}

ManageAnimals::~ManageAnimals()
{
    delete ui;
}

void ManageAnimals::on_pushButton_2_clicked()
{
    EditPageAnimals eda(ui->lineEdit->text());
    eda.setModal(true);
    eda.exec();
}


void ManageAnimals::on_pushButton_clicked()
{
    ProtocolFilterAnimals pfa;
    pfa.changeCode();
    pfa.sendMessage(ui->Varsta->currentText(),ui->Sex->currentText(),ui->Locatie->currentText(),ui->Talie->currentText(),ui->Specie->currentText());
    pfa.manageMessageRecived();
    AdminAnimalSearch aas;
    aas.setModal(true);
    aas.exec();

}


void ManageAnimals::on_pushButton_3_clicked()
{
    close();
}

