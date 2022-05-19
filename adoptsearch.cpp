#include "adoptsearch.h"
#include "ui_adoptsearch.h"
#include "system.h"
#include "QStringList"

AdoptSearch::AdoptSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdoptSearch)
{
    ui->setupUi(this);
    qDebug()<<System::getInstance().getVectAnimalSize()<<"LOOOK HERE!";
    for(int i=0;i<System::getInstance().getVectAnimalSize();i++){
    QString entry=System::getInstance().getAnimal(i)->getId();
    entry=entry.append(" ");
    entry.append(System::getInstance().getAnimal(i)->getSpecies());
    QListWidgetItem *item=new QListWidgetItem(entry);
    ui->listWidget->addItem(item);
    }
//    QListWidgetItem *item1=new QListWidgetItem("Catel");
//    ui->listWidget->addItem(item1);
//    QListWidgetItem *item2=new QListWidgetItem("Pisica");
//      ui->listWidget->addItem(item2);
//    QListWidgetItem *item3=new QListWidgetItem("Papagal");
//      ui->listWidget->addItem(item3);
}

AdoptSearch::~AdoptSearch()
{
    System::getInstance().emptySearchAnimals();
    delete ui;
}

void AdoptSearch::on_pushButton_clicked()
{
    QStringList temp=ui->listWidget->currentItem()->text().split(" ");
    AnimalProfile prof(temp[0]);
    prof.setModal(true);
    prof.exec();
}

