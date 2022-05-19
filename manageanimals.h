#ifndef MANAGEANIMALS_H
#define MANAGEANIMALS_H

#include <QDialog>

namespace Ui {
class ManageAnimals;
}

class ManageAnimals : public QDialog
{
    Q_OBJECT

public:
    explicit ManageAnimals(QWidget *parent = nullptr);
    ~ManageAnimals();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ManageAnimals *ui;
};

#endif // MANAGEANIMALS_H
