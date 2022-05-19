#ifndef FILTERADOPT_H
#define FILTERADOPT_H

#include <QDialog>
#include <adoptsearch.h>

namespace Ui {
class FilterAdopt;
}

class FilterAdopt : public QDialog
{
    Q_OBJECT

public:
    explicit FilterAdopt(QWidget *parent = nullptr);
    ~FilterAdopt();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::FilterAdopt *ui;
};

#endif // FILTERADOPT_H
