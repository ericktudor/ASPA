#include "campaign.h"
#include "ui_campaign.h"


Campaign::Campaign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Campaign)
{
    ui->setupUi(this);



}

Campaign::~Campaign()
{
    delete ui;
}

void Campaign::on_pushButton_2_clicked()
{
    qDebug()<<ui->calendarWidget->selectedDate();
    QString data=ui->calendarWidget->selectedDate().toString();
    qDebug()<<data;

}


void Campaign::on_pushButton_clicked()
{
    close();
}

