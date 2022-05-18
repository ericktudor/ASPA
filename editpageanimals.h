#ifndef EDITPAGEANIMALS_H
#define EDITPAGEANIMALS_H

#include <QDialog>

namespace Ui {
class EditPageAnimals;
}

class EditPageAnimals : public QDialog
{
    Q_OBJECT

public:
    explicit EditPageAnimals(QString id,QWidget *parent = nullptr);
    ~EditPageAnimals();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditPageAnimals *ui;
    QString id;
};

#endif // EDITPAGEANIMALS_H
