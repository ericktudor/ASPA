#ifndef VACCINAREINFO_H
#define VACCINAREINFO_H

#include <QDialog>

namespace Ui {
class VaccinareInfo;
}

class VaccinareInfo : public QDialog
{
    Q_OBJECT

public:
    explicit VaccinareInfo(QWidget *parent = nullptr);
    ~VaccinareInfo();

private:
    Ui::VaccinareInfo *ui;
};

#endif // VACCINAREINFO_H
