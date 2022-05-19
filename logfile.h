#ifndef LOGFILE_H
#define LOGFILE_H

#include <QDialog>

namespace Ui {
class LogFile;
}

class LogFile : public QDialog
{
    Q_OBJECT

public:
    explicit LogFile(QWidget *parent = nullptr);
    ~LogFile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LogFile *ui;
};

#endif // LOGFILE_H
