#ifndef REQUESTPAGE_H
#define REQUESTPAGE_H

#include <QDialog>
#include "system.h"

namespace Ui {
class RequestPage;
}

class RequestPage : public QDialog
{
    Q_OBJECT

public:
    explicit RequestPage(QString id,QWidget *parent = nullptr);
    ~RequestPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::RequestPage *ui;
    Request* req;
};

#endif // REQUESTPAGE_H
