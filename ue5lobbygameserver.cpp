#include "ue5lobbygameserver.h"

#include <QStringLiteral>
#include <QWebSocket>

UE5LobbyGameServer::UE5LobbyGameServer(QObject *parent)
    : QObject{parent}
{
}

UE5LobbyGameServer::~UE5LobbyGameServer()
{
    if(nullptr != WebSocketServer)
    {
        WebSocketServer->close();
        qDeleteAll(Clients.begin(), Clients.end());
    }
}


void UE5LobbyGameServer::StartServer(quint16 Port)
{
    QString  ServerName = "Labby Server";
    WebSocketServer = new QWebSocketServer(ServerName, QWebSocketServer::NonSecureMode, this);
    if(nullptr != WebSocketServer)
    {
        if( const bool Status = WebSocketServer->listen(QHostAddress::Any, Port); Status)
        {
            qDebug() << "WebSocket server started on port: "<<Port;
            connect(WebSocketServer, &QWebSocketServer::newConnection, this, &UE5LobbyGameServer::onNewConnection);
        }
        else
        {
            qDebug()<< "WebSocket server failed to start";
        }
    }
}


void UE5LobbyGameServer::onNewConnection()
{
    if(nullptr != WebSocketServer)
    {
        QWebSocket * client = WebSocketServer->nextPendingConnection();
            // connect slot
        connect(client, &QWebSocket::textMessageReceived, this, &UE5LobbyGameServer::ProcessTextMessage);
        connect(client, &QWebSocket::disconnected, this, &UE5LobbyGameServer::SocketDisconnected);
        // Add client into list
        Clients << client;

        qDebug() << "New client connected";
    }
}

void UE5LobbyGameServer::ProcessTextMessage(QString message)
{

}

void UE5LobbyGameServer::SocketDisconnected()
{
    QWebSocket * client = qobject_cast<QWebSocket *>(sender());
    if (nullptr != client) {
        Clients.removeAll(client);
        client->deleteLater();
        qDebug() << "Client disconnected";
    }
}
