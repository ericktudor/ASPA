#ifndef ANIMALPROFILE_H
#define ANIMALPROFILE_H

#include <QDialog>
#include <animal.h>

namespace Ui {
class AnimalProfile;
}

class AnimalProfile : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalProfile(QString data,QWidget *parent = nullptr);
    ~AnimalProfile();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AnimalProfile *ui;
    Animal* selected;
};

#endif // ANIMALPROFILE_H
