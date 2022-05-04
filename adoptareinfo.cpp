#include "adoptareinfo.h"
#include "ui_adoptareinfo.h"

AdoptareInfo::AdoptareInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdoptareInfo)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

AdoptareInfo::~AdoptareInfo()
{
    delete ui;
}
