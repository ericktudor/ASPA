#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <QDialog>

namespace Ui {
class Campaign;
}

class Campaign : public QDialog
{
    Q_OBJECT

public:
    explicit Campaign(QWidget *parent = nullptr);
    ~Campaign();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Campaign *ui;
};

#endif // CAMPAIGN_H
