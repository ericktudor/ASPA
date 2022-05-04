#include "requestslist.h"
#include "ui_requestslist.h"
#include "system.h"

RequestsList::RequestsList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestsList)
{
    ui->setupUi(this);
    for(int i=0;i<System::getInstance().getVectRequestSize();i++){
        QString entry=System::getInstance().getRequest(i)->getId_Req();
        entry=entry.append(" ");
        entry.append(System::getInstance().getRequest(i)->getName());
        entry=entry.append(" ");
        entry.append(System::getInstance().getRequest(i)->getSurname());
        QListWidgetItem *item=new QListWidgetItem(entry);
        ui->listWidget->addItem(item);
    }
}

RequestsList::~RequestsList()
{
    delete ui;
}
