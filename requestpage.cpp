#include "requestpage.h"
#include "ui_requestpage.h"

RequestPage::RequestPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RequestPage)
{
    ui->setupUi(this);
}

RequestPage::~RequestPage()
{
    delete ui;
}
