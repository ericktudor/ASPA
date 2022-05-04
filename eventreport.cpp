#include "eventreport.h"
#include "ui_eventreport.h"

EventReport::EventReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventReport)
{
    ui->setupUi(this);
}

EventReport::~EventReport()
{
    delete ui;
}

void EventReport::on_pushButton_2_clicked()
{
    close();
}

