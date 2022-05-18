#ifndef ADMINANIMALSEARCH_H
#define ADMINANIMALSEARCH_H

#include <QDialog>

namespace Ui {
class AdminAnimalSearch;
}

class AdminAnimalSearch : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAnimalSearch(QWidget *parent = nullptr);
    ~AdminAnimalSearch();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminAnimalSearch *ui;
};

#endif // ADMINANIMALSEARCH_H
