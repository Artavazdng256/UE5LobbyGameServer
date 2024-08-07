#ifndef UE5LOBBYGAMESERVER_H
#define UE5LOBBYGAMESERVER_H

#include <QObject>
#include <QWebSocketServer>

class UE5LobbyGameServer : public QObject
{
    Q_OBJECT
public:
    explicit UE5LobbyGameServer(QObject *parent = nullptr);

    ~UE5LobbyGameServer();

signals:

private slots:

    void onNewConnection();

private:

    QWebSocketServer * WebSocketServer = nullptr;

    QList<QWebSocket *> Clients;

public:

    void StartServer(quint16 Port);

    void ProcessTextMessage(QString message);

    void SocketDisconnected();
};

#endif // UE5LOBBYGAMESERVER_H
