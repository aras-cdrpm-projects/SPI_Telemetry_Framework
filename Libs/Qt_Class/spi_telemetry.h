#ifndef SPI_TELEMETRY_H
#define SPI_TELEMETRY_H
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include <QDebug>
#include <QObject>
#include <QTimer>
#include <string>
#include <wiringPiSPI.h>


#define IMP_BASEADDRESS     0
#define IMU_BASEADDRESS     30
#define RPUs_BASEADDRESS    68
#define KYES_BASEADDRESS    102
#define SLIDERS_BASEADDRESS 110

#define SPI_PATH "/dev/spidev1.2"


class SPI_Telemetry : public QObject
{
    Q_OBJECT
public:
    explicit SPI_Telemetry(QObject *parent = nullptr,int SPI_CHANEL=0,int SPI_CLK=500000);
    void IMP_Read(float *pos,float *q);
    void IMU_Read(int32_t *a,int32_t *g,int32_t *m);
    void RPUs_Read(int32_t *encoders,int32_t *forces);
    void Keys_Set(int key1,int key2,int key3,int key4);
    void SlidersSet(int slider1, int slider2, int slider3, int slider4);

    void IMP_ReadSw(float *pos,float *q);
    void IMU_ReadSw(int32_t *a,int32_t *g,int32_t *m);
    void RPUs_ReadSw(int32_t *encoders,int32_t *forces);
    void Keys_SetSw(int key1,int key2,int key3,int key4);
    void SlidersSetSw(int slider1, int slider2, int slider3, int slider4);
    void updateTransaction(void);

private:
    uint8_t spi_regs[128];
    uint8_t spi_txBuff[128];
    uint8_t spi_rxBuff[128];


    union{
        struct
        {
            float Pos[3];
            float q[4];

        }Data;
        uint8_t buffer[28];
    }IMP;//28 Bytes
    union{
        struct
        {
            int32_t m[3];
            int32_t a[3];
            int32_t g[3];
        }Data;
        uint8_t buffer[36];
    }IMU;//36 Bytes
    union{
        struct
        {
            uint8_t Keys[4];
        }Data;
        uint8_t buffer[4];
    }KEYs;//4 Bytes
    union{
        struct
        {
            uint8_t sliders[4];
        }Data;
        uint8_t buffer[4];
    }Sliders;//4 Bytes
    union{
        struct
        {
            int32_t  Enc[4];
            int32_t  force[4];
        }Data;
        uint8_t buffer[32];
    }RPUs;//32 Bytes
int spiFD;
int chanel;
unsigned int spiCLK;

void transaction(uint8_t *txBuff,uint8_t *rxBuff,int len);
void regWrite(uint8_t Address,uint8_t *data,int len);
void regRead(uint8_t Address,uint8_t *data,int len);
void regReadSw(uint8_t Address, uint8_t *data, int len);
void regWriteSw(uint8_t Address,uint8_t *data,int len);
signals:

public slots:
};

#endif // SPI_TELEMETRY_H
