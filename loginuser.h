#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
//#include "tcpclient.h"
#include "system.h"


namespace Ui {
class LoginUser;
}

class LoginUser : public QDialog
{
    Q_OBJECT

public:
    explicit LoginUser(QWidget *parent = nullptr);
    ~LoginUser();
    //TcpClient client;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LoginUser *ui;
};

#endif // LOGINUSER_H
