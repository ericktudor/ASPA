#ifndef STERILIZAREINFO_H
#define STERILIZAREINFO_H

#include <QDialog>

namespace Ui {
class SterilizareInfo;
}

class SterilizareInfo : public QDialog
{
    Q_OBJECT

public:
    explicit SterilizareInfo(QWidget *parent = nullptr);
    ~SterilizareInfo();

private:
    Ui::SterilizareInfo *ui;
};

#endif // STERILIZAREINFO_H
