#include "adoptlist.h"
#include "ui_adoptlist.h"

AdoptList::AdoptList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdoptList)
{
    ui->setupUi(this);
}

AdoptList::~AdoptList()
{
    delete ui;
}
