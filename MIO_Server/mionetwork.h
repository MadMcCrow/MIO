#ifndef MIONETWORK_H
#define MIONETWORK_H

#include <QObject>
#include <QtNetwork>
#include <QString>

class MIONetwork : public QObject
{
    Q_OBJECT
public:
    MIONetwork(){m_server = new QTcpServer;}
    ~MIONetwork(){delete m_server;}

public slots:
    void startNetworking_c();
    void sendData_c(quint8 key, QDataStream &stream);

private slots:
    void newConnection_c();
    void endConnection_c();
    void qtcpReceived_c();

signals:
    void receivedData_s(quint8, QDataStream &);
    void toLog_s(QString, int);
private:
    QTcpServer*         m_server;
    QList<QTcpSocket *> m_clients;
};

#endif // MIONETWORK_H
