#include "serialtelemetry.h"

serialTelemetry::serialTelemetry(QObject *parent) : QObject(parent)
{
    mySerial= new QSerialPort(this);
    mySerial->setPortName("/dev/ttyACM0");
    mySerial->setBaudRate(QSerialPort::Baud115200);
    mySerial->setDataBits(QSerialPort::Data8);
    mySerial->setFlowControl(QSerialPort::NoFlowControl);
    mySerial->setStopBits(QSerialPort::OneStop);
    mySerial->open(QSerialPort::ReadWrite);
    connect(mySerial,SIGNAL(readyRead()),this,SLOT(dataRes()));
    incomplete=0;
    gain=1;
}

serialTelemetry::~serialTelemetry()
{
    mySerial->close();

}

double serialTelemetry::readVal()
{
    return( (double) Packet.Data.speed)*gain;
}

void serialTelemetry::setGain(double k)
{
    gain=k;
}


void serialTelemetry::dataRes()
{
    //.qDebug() <<mySerial->bytesAvailable();
    char dat;
    while(mySerial->bytesAvailable()){

        if(incomplete==0)
        {
            if(mySerial->bytesAvailable()<2)                                        //if both headers are not availble in the buffer, break
                break;
            mySerial->getChar(&dat);
            if(dat=='a')
            {
                mySerial->getChar(&dat);
                if(dat=='b')
                {                                                                   //header is detected, the rest is data
                    if(mySerial->bytesAvailable()<Data_Buffer_Size)                 //The rest is in buffer
                    {
                        incomplete=1;
                        break;
                    }else{                                                          //data is not complete, break and try to read later
                       mySerial->read(Packet.buffer,Data_Buffer_Size);
                       incomplete=0;
                       emit dataAvalable();
                       //qDebug() <<"val"<<Packet.Data.speed;

                    }
                }
            }
        }else{
            if(mySerial->bytesAvailable()<Data_Buffer_Size)
            {
                incomplete=1;                                                      //data is not complet in the buffer yet
                break;
            }else
            {
                mySerial->read(Packet.buffer,Data_Buffer_Size);                    //we are good to get the data
                incomplete=0;
                emit dataAvalable();
                //qDebug() <<"val"<<Packet.Data.speed;
            }
        }


    }
}
