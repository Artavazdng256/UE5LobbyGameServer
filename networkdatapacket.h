#ifndef NETWORKDATAPACKET_H
#define NETWORKDATAPACKET_H

#include <QObject>
#include <QString>

class FNetworkDataPacket : public QObject
{
    Q_OBJECT
public:
    explicit FNetworkDataPacket(QObject *parent = nullptr);

signals:

private:

    QString Signature{};

    QString DataType{};

    QString Data{};


public:

    friend QDataStream &operator<<(QDataStream & Out, const FNetworkDataPacket & NetworkDataPacket);
    friend QDataStream &operator>>(QDataStream & In, FNetworkDataPacket & NetworkDataPacket);

};

#endif // NETWORKDATAPACKET_H
