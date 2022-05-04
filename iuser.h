#ifndef IUSER_H
#define IUSER_H

#include <QObject>
#include <QString>

class IUser : public QObject
{
    Q_OBJECT


public:
    explicit IUser(QObject *parent = nullptr);
    virtual QString getUser()=0;
    virtual QString getId()=0;

signals:

};

#endif // IUSER_H
