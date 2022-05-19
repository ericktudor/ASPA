#include "adminanimalsearch.h"
#include "ui_adminanimalsearch.h"
#include "system.h"
#include "editpageanimals.h"


AdminAnimalSearch::AdminAnimalSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAnimalSearch)
{
    ui->setupUi(this);
    for(int i=0;i<System::getInstance().getVectAnimalSize();i++){
    QString entry=System::getInstance().getAnimal(i)->getId();
    entry=entry.append(" ");
    entry.append(System::getInstance().getAnimal(i)->getSpecies());
    QListWidgetItem *item=new QListWidgetItem(entry);
    ui->listWidget->addItem(item);
    }
}

AdminAnimalSearch::~AdminAnimalSearch()
{
    System::getInstance().emptySearchAnimals();
    delete ui;
}

void AdminAnimalSearch::on_pushButton_clicked()
{
    QStringList temp=ui->listWidget->currentItem()->text().split(" ");
    EditPageAnimals prof(temp[0]);
    prof.setModal(true);
    prof.exec();
    close();
}

