#ifndef REQUESTSLIST_H
#define REQUESTSLIST_H

#include <QDialog>

namespace Ui {
class RequestsList;
}

class RequestsList : public QDialog
{
    Q_OBJECT

public:
    explicit RequestsList(QWidget *parent = nullptr);
    ~RequestsList();

private:
    Ui::RequestsList *ui;
};

#endif // REQUESTSLIST_H
