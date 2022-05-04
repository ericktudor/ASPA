#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
LoginUser uslog(this);
uslog.setModal(true);
uslog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    Register register1;
    register1.setModal(true);
    register1.exec();

}


void MainWindow::on_pushButton_3_clicked()
{
    AdminLogin admlog;
    admlog.setModal(true);
    admlog.exec();

}

