#ifndef ADOPTLIST_H
#define ADOPTLIST_H

#include <QDialog>

namespace Ui {
class AdoptList;
}

class AdoptList : public QDialog
{
    Q_OBJECT

public:
    explicit AdoptList(QWidget *parent = nullptr);
    ~AdoptList();

private:
    Ui::AdoptList *ui;
};

#endif // ADOPTLIST_H
