#ifndef INFORMATIONSMENU_H
#define INFORMATIONSMENU_H

#include <QDialog>

namespace Ui {
class InformationsMenu;
}

class InformationsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit InformationsMenu(QWidget *parent = nullptr);
    ~InformationsMenu();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::InformationsMenu *ui;
};

#endif // INFORMATIONSMENU_H
