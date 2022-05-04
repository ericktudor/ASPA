#ifndef REQUESTPAGE_H
#define REQUESTPAGE_H

#include <QDialog>

namespace Ui {
class RequestPage;
}

class RequestPage : public QDialog
{
    Q_OBJECT

public:
    explicit RequestPage(QWidget *parent = nullptr);
    ~RequestPage();

private:
    Ui::RequestPage *ui;
};

#endif // REQUESTPAGE_H
