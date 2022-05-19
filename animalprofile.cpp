#include "animalprofile.h"
#include "ui_animalprofile.h"
#include "system.h"
#include "QMessageBox"
#include "adoptformular.h"

AnimalProfile::AnimalProfile(QString data,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfile)
{
    ui->setupUi(this);

    for(int i=0;i<System::getInstance().getVectAnimalSize();i=i+1){
        if(data==System::getInstance().getAnimal(i)->getId()){
            this->selected=System::getInstance().getAnimal(i);
        }

    }

    if(selected==nullptr){
        QMessageBox::warning(this,"Error!","The Selected Animal couldn't be loaded!");

    }
    else{
        ui->IDRaspuns->setText(selected->getId());
        ui->LocatieRaspuns->setText(selected->getLocation());
        ui->SexRaspuns->setText(selected->getSex());
        ui->SpecieRaspuns->setText(selected->getSpecies());
        ui->TalieRaspuns->setText(selected->getSize());
        int x=selected->getAge();
        QString s = QString::number(x);
        ui->VarstaRaspuns->setText(s);

    }
    if(ui->SpecieRaspuns->text()=="Caine"){ui->groupBox_2->setStyleSheet("#groupBox_2{border-image: url(:/img/dog-logo.png);border-radius:80px;}");}
    else if(ui->SpecieRaspuns->text()=="Pisica"){ui->groupBox_2->setStyleSheet("#groupBox_2{border-image: url(:/img/cat-logo.webp);border-radius:80px;}");}
    else if(ui->SpecieRaspuns->text()=="Hamster"){ui->groupBox_2->setStyleSheet("#groupBox_2{border-image: url(:/img/hamster-logo.jpg);border-radius:80px;}");}
    else if(ui->SpecieRaspuns->text()=="Papagal"){ui->groupBox_2->setStyleSheet("#groupBox_2{border-image: url(:/img/parrot-logo.jpg);border-radius:80px;}");}


}

AnimalProfile::~AnimalProfile()
{
    delete ui;
}

void AnimalProfile::on_pushButton_clicked()
{
    AdoptFormular adpt;
    adpt.setModal(true);
    adpt.exec();
    close();
}


void AnimalProfile::on_pushButton_2_clicked()
{
    close();
}

