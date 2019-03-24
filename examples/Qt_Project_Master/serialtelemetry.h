#ifndef SERIALTELEMETRY_H
#define SERIALTELEMETRY_H
#define Data_Buffer_Size 4
#include <QObject>
//#include <QSerialPort>
#include <QDebug>

class serialTelemetry : public QObject
{
    Q_OBJECT
public:
    explicit serialTelemetry(QObject *parent = nullptr);
     ~serialTelemetry();
    double readVal();
    void   setGain(double k);
private:
        QSerialPort *mySerial;
    union{
        struct
        {
          int32_t speed;
        }Data;
        char buffer[4];
    }Packet;
    int incomplete;
    double gain;


signals:
    void dataAvalable();

public slots:
    void dataRes();

};

#endif // SERIALTELEMETRY_H
