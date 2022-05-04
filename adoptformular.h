#ifndef ADOPTFORMULAR_H
#define ADOPTFORMULAR_H

#include <QDialog>

namespace Ui {
class AdoptFormular;
}

class AdoptFormular : public QDialog
{
    Q_OBJECT

public:
    explicit AdoptFormular(QWidget *parent = nullptr);
    ~AdoptFormular();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AdoptFormular *ui;
};

#endif // ADOPTFORMULAR_H
