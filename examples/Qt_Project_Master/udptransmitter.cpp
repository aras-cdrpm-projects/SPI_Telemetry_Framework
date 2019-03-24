#include "udptransmitter.h"

UDPTransmitter::UDPTransmitter(QObject *parent) : QObject(parent)
{
       udp_socket = new QUdpSocket(this);
}

void UDPTransmitter::sendData(char *data, unsigned int length)
{
    //Binary Data Transmit
//        Transmit_Packet.Data.Val1=signal1;
//        Transmit_Packet.Data.VAl2=signal2;
//        udp_socket->writeDatagram(Transmit_Packet.buffer,16, QHostAddress("192.168.137.2"), 8000 );
//    //Text Data Transfer
//        QString mess;
//        mess.sprintf("Value1= %f\t,\tValue2= %f\n",signal1,signal2);
//        udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress("192.168.137.2"), 8000 );
//        udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress::AnyIPv4, 8000 );
//        udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress::AnyIPv4, 8000 );
//        udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress::AnyIPv4, 8000 );
//        udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress::AnyIPv4, 8000 );
//        udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress::AnyIPv4, 8000 );

}
void UDPTransmitter::sendData(void)
{
    QString mess;
    mess.sprintf("Value1= %f\t,\tValue2= %f\n",12,143);
    udp_socket->writeDatagram(mess.toStdString().c_str(),mess.size(),QHostAddress("192.168.137.2"), 8000 );
    //for(int i=0;i<80000000;i++);

}
