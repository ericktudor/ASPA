#include "informationsmenu.h"
#include "ui_informationsmenu.h"
#include "sterilizareinfo.h"
#include "adoptareinfo.h"
#include "vaccinareinfo.h"

InformationsMenu::InformationsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformationsMenu)
{
    ui->setupUi(this);
}

InformationsMenu::~InformationsMenu()
{
    delete ui;
}

void InformationsMenu::on_pushButton_3_clicked()
{
    AdoptareInfo x;
    x.setModal(true);
    x.exec();
}


void InformationsMenu::on_pushButton_2_clicked()
{
    SterilizareInfo s;
    s.setModal(true);
    s.exec();
}


void InformationsMenu::on_pushButton_4_clicked()
{
    VaccinareInfo v;
    v.setModal(true);
    v.exec();
}


void InformationsMenu::on_pushButton_clicked()
{
    close();
}

