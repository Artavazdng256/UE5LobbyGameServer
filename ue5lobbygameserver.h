#ifndef UE5LOBBYGAMESERVER_H
#define UE5LOBBYGAMESERVER_H

#include <QObject>
#include <QUdpSocket>

class UE5LobbyGameServer : public QObject
{
    Q_OBJECT
public:
    explicit UE5LobbyGameServer(QObject *parent = nullptr);

    ~UE5LobbyGameServer();

signals:

private slots:

    void processPendingDatagrams();

private:

    QUdpSocket * UdpSocket = nullptr;

public:

    void StartServer(quint16 port);
};

#endif // UE5LOBBYGAMESERVER_H
