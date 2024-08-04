#include "networkdatapacket.h"

FNetworkDataPacket::FNetworkDataPacket(QObject *parent)
    : QObject{parent}
{}


QDataStream &operator<<(QDataStream & Out, const FNetworkDataPacket & NetworkDataPacket)
{
    Out<<NetworkDataPacket.Signature
        <<NetworkDataPacket.DataType
        <<NetworkDataPacket.Data;
    return Out;
}

QDataStream &operator>>(QDataStream & In, FNetworkDataPacket & NetworkDataPacket)
{
    In>>NetworkDataPacket.Signature
        >>NetworkDataPacket.DataType
        >>NetworkDataPacket.Data;
    return In;
}
