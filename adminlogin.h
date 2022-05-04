#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "system.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AdminLogin *ui;
};

#endif // ADMINLOGIN_H
