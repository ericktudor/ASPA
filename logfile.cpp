#include "logfile.h"
#include "ui_logfile.h"
#include "system.h"

LogFile::LogFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogFile)
{
    ui->setupUi(this);
    ui->textEdit->setText(System::getInstance().getLogFile());
    ui->textEdit->setReadOnly(true);
}

LogFile::~LogFile()
{
    delete ui;
}

void LogFile::on_pushButton_clicked()
{
    close();
}

