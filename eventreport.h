#ifndef EVENTREPORT_H
#define EVENTREPORT_H

#include <QDialog>

namespace Ui {
class EventReport;
}

class EventReport : public QDialog
{
    Q_OBJECT

public:
    explicit EventReport(QWidget *parent = nullptr);
    ~EventReport();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::EventReport *ui;
};

#endif // EVENTREPORT_H
