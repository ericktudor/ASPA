#include "eventreport.h"
#include "ui_eventreport.h"
#include "protocolreportevent.h"

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


void EventReport::on_pushButton_clicked()
{
   ProtocolReportEvent pre;
   QString s=ui->Descriere->toPlainText();
   pre.sendMessage(ui->Nume->text(),ui->Prenume->text(),ui->Telefon->text(),ui->Locatie->text(),s);
   if(pre.receivePermision()){QMessageBox::information(this,"Succes","Event Reported");
   close();
   }
   else{

       QMessageBox::warning(this,"Failure","Fail!Try again!");

   }
}




