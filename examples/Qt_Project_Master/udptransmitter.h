#ifndef UDPTRANSMITTER_H
#define UDPTRANSMITTER_H

#include <QObject>
#include <QUdpSocket>

class UDPTransmitter : public QObject
{
    Q_OBJECT
public:
    explicit UDPTransmitter(QObject *parent = nullptr);
    void sendData(char *data,unsigned int length);
    void sendData(void);

private:
    QUdpSocket *udp_socket;
    quint8 destAddress[4];

signals:

public slots:
};

#endif // UDPTRANSMITTER_H
