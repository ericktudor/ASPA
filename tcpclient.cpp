#include "tcpclient.h"
#include <QDebug>

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    connect(&_socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
    connect(&_socket, &QTcpSocket::errorOccurred, this, &TcpClient::onErrorOccurred);
    connect(&_socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
}

void TcpClient::connectToServer(const QString &ip, const QString &port)
{
    _socket.connectToHost(ip, port.toUInt());
}

void TcpClient::sendMessage(const QString &message)
{

    _socket.write(message.toUtf8(),message.size());
    _socket.waitForBytesWritten();
}

QString TcpClient::receive()
{
    _socket.waitForReadyRead();
    QByteArray str=_socket.readAll();
    _socket.waitForReadyRead();
    str=_socket.readAll();
    QString s(str);
    //
   return s.toUtf8();

}



void TcpClient::onConnected()
{
    qInfo() << "Connected to host.";
}

QString TcpClient::onReadyRead()
{
   // const auto message = _socket.readAll();
    //emit newMessage(message);

    //QByteArray str = _socket.readAll();
   // QString s (str);

    //qDebug()<<s;
    qDebug()<<"Receving!";
    return "";
}

void TcpClient::onErrorOccurred(QAbstractSocket::SocketError error)
{
    qWarning() << "Error:" << error;
}
