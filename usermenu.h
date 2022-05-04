#ifndef USERMENU_H
#define USERMENU_H


#include <QDialog>
#include <filteradopt.h>

namespace Ui {
class UserMenu;
}

class UserMenu : public QDialog
{
    Q_OBJECT

public:
    explicit UserMenu(QWidget *parent = nullptr);
    ~UserMenu();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::UserMenu *ui;
};

#endif // USERMENU_H
