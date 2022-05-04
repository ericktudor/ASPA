#include "vaccinareinfo.h"
#include "ui_vaccinareinfo.h"

VaccinareInfo::VaccinareInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VaccinareInfo)
{
    ui->setupUi(this);
     ui->textEdit->setReadOnly(true);
}

VaccinareInfo::~VaccinareInfo()
{
    delete ui;
}
