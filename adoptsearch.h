#ifndef ADOPTSEARCH_H
#define ADOPTSEARCH_H

#include <QDialog>
#include <animalprofile.h>

namespace Ui {
class AdoptSearch;
}

class AdoptSearch : public QDialog
{
    Q_OBJECT

public:
    explicit AdoptSearch(QWidget *parent = nullptr);
    ~AdoptSearch();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdoptSearch *ui;
};

#endif // ADOPTSEARCH_H
