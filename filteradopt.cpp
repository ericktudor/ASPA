#include "filteradopt.h"
#include "ui_filteradopt.h"
#include "protocolfilteranimals.h"

FilterAdopt::FilterAdopt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterAdopt)
{
    ui->setupUi(this);
}

FilterAdopt::~FilterAdopt()
{
    delete ui;
}

void FilterAdopt::on_pushButton_2_clicked()
{
    QString sex= ui->comboBox->currentText();
    QString varsta=ui->comboBox_2->currentText();
    QString locatie=ui->comboBox_3->currentText();
    QString talie=ui->comboBox_4->currentText();
    QString specie=ui->comboBox_5->currentText();
    ProtocolFilterAnimals pr;
    pr.sendMessage(varsta,sex,locatie,talie,specie);
    pr.manageMessageRecived();
    AdoptSearch results;
    hide();
    results.setModal(true);
    results.exec();

}

