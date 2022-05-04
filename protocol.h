#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "iprotocol.h"
#include <QString>
#include <system.h>
#include <QMessageBox>
#include <QStringList>

class Protocol : public IProtocol
{
protected:
QString message;
QString delimiter;
public:
    Protocol();
    void setDelimiter(QString delimiter);
    bool receivePermision();
};

#endif // PROTOCOL_H
