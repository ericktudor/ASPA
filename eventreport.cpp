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
   if(ui->Nume->text().length()>24||ui->Prenume->text().length()>24||ui->Telefon->text().length()>24||ui->Locatie->text().length()>24||s.length()>1000){
       QMessageBox::warning(this,"Error","Max number of characters reached!");
   }
   else{
   pre.sendMessage(ui->Nume->text(),ui->Prenume->text(),ui->Telefon->text(),ui->Locatie->text(),s);
   if(pre.receivePermision()){QMessageBox::information(this,"Succes","Event Reported");
   close();
   }
   else{

       QMessageBox::warning(this,"Failure","Fail!Try again!");

   }
   }
}




