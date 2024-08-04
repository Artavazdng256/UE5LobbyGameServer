#include "ue5lobbygameserver.h"

UE5LobbyGameServer::UE5LobbyGameServer(QObject *parent)
    : QObject{parent}
{
    UdpSocket = new QUdpSocket(this);
}

UE5LobbyGameServer::~UE5LobbyGameServer()
{
    if(nullptr != UdpSocket)
    {
        UdpSocket->close();
        qDebug()<< "Close Udp socket \n";
    }
}

void UE5LobbyGameServer::processPendingDatagrams()
{
    while (UdpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(UdpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        UdpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        QString datagramString = QString::fromUtf8(datagram);
        qDebug()<<datagramString;

    }
}

void UE5LobbyGameServer::StartServer(quint16 port)
{
    if(nullptr !=UdpSocket)
    {

        if(const bool bStatus = UdpSocket->bind(QHostAddress::Any, port); bStatus)
        {
            qDebug() << "Rebound to new port successfully.";
            connect(UdpSocket, &QUdpSocket::readyRead, this, &UE5LobbyGameServer::processPendingDatagrams);
        }
        else
        {
            qWarning() << "Failed to bind to new port:" << UdpSocket->errorString();
        }
    }
}
