#ifndef ADOPTAREINFO_H
#define ADOPTAREINFO_H

#include <QDialog>

namespace Ui {
class AdoptareInfo;
}

class AdoptareInfo : public QDialog
{
    Q_OBJECT

public:
    explicit AdoptareInfo(QWidget *parent = nullptr);
    ~AdoptareInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdoptareInfo *ui;
};

#endif // ADOPTAREINFO_H
