#include "manageanimals.h"
#include "ui_manageanimals.h"

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
