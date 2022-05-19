#ifndef ADDCAMPAIGN_H
#define ADDCAMPAIGN_H

#include <QDialog>

namespace Ui {
class AddCampaign;
}

class AddCampaign : public QDialog
{
    Q_OBJECT

public:
    explicit AddCampaign(QWidget *parent = nullptr);
    ~AddCampaign();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddCampaign *ui;
};

#endif // ADDCAMPAIGN_H
