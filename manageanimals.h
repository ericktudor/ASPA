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

private:
    Ui::ManageAnimals *ui;
};

#endif // MANAGEANIMALS_H
