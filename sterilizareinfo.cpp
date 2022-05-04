#include "sterilizareinfo.h"
#include "ui_sterilizareinfo.h"

SterilizareInfo::SterilizareInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SterilizareInfo)
{
    ui->setupUi(this);
     ui->textEdit->setReadOnly(true);
}

SterilizareInfo::~SterilizareInfo()
{
    delete ui;
}
