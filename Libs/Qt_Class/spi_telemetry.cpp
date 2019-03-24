#include "spi_telemetry.h"

SPI_Telemetry::SPI_Telemetry(QObject *parent , int SPI_CHANEL,int SPI_CLK) : QObject(parent)
{
    int ret,bits=8;
    uint8_t mode = 0;
    spiCLK=SPI_CLK;
    memset((uint8_t *)spi_regs,0x01,sizeof(spi_regs));
    if ((spiFD = open(SPI_PATH, O_RDWR))<0) {
    qDebug()<<"SPI Error: Can't open device.";
    }
    if (ioctl(spiFD, SPI_IOC_WR_MODE, &mode)==-1) {
    qDebug()<<"SPI: Can't set SPI mode.";
    }
    if (ioctl(spiFD, SPI_IOC_RD_MODE, &mode)==-1) {
    qDebug()<<"SPI: Can't get SPI mode.";
    }
    ret = ioctl(spiFD, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1)
            qDebug()<<("can't set bits per word");

    ret = ioctl(spiFD, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1)
             qDebug()<<("can't get bits per word");

    /*
     * max speed hz
     */
    ret = ioctl(spiFD, SPI_IOC_WR_MAX_SPEED_HZ, &spiCLK);
    if (ret == -1)
             qDebug()<<("can't set max speed hz");

    ret = ioctl(spiFD, SPI_IOC_RD_MAX_SPEED_HZ, &spiCLK);
    if (ret == -1)
    qDebug()<<("can't get max speed hz");
}

void SPI_Telemetry::IMP_Read(float *pos, float *q)
{
    regRead(IMP_BASEADDRESS,IMP.buffer,sizeof(IMP.buffer));
    pos[0]=IMP.Data.Pos[0];
    pos[1]=IMP.Data.Pos[1];
    pos[2]=IMP.Data.Pos[2];
    q[0]=IMP.Data.q[0];
    q[1]=IMP.Data.q[1];
    q[2]=IMP.Data.q[2];
    q[3]=IMP.Data.q[3];
}

void SPI_Telemetry::IMU_Read(int32_t *a, int32_t *g, int32_t *m)
{
    regRead(IMU_BASEADDRESS,IMU.buffer,sizeof(IMU.buffer));
    a[0]=IMU.Data.a[0];
    a[1]=IMU.Data.a[1];
    a[2]=IMU.Data.a[2];
    g[0]=IMU.Data.g[0];
    g[1]=IMU.Data.g[1];
    g[2]=IMU.Data.g[2];
    m[0]=IMU.Data.m[0];
    m[1]=IMU.Data.m[1];
    m[2]=IMU.Data.m[2];
}

void SPI_Telemetry::RPUs_Read(int32_t *encoders, int32_t *forces)
{
    regRead(RPUs_BASEADDRESS,RPUs.buffer,sizeof(RPUs.buffer));
    encoders[0]=RPUs.Data.Enc[0];
    encoders[1]=RPUs.Data.Enc[1];
    encoders[2]=RPUs.Data.Enc[2];
    encoders[3]=RPUs.Data.Enc[3];
    forces[0]=RPUs.Data.force[0];
    forces[1]=RPUs.Data.force[1];
    forces[2]=RPUs.Data.force[2];
    forces[3]=RPUs.Data.force[3];
}

void SPI_Telemetry::Keys_Set(int key1, int key2, int key3, int key4)
{
    KEYs.Data.Keys[0]=key1;
    KEYs.Data.Keys[1]=key2;
    KEYs.Data.Keys[2]=key3;
    KEYs.Data.Keys[3]=key4;
    regWrite(KYES_BASEADDRESS,KEYs.buffer,sizeof(KEYs.buffer));
}

void SPI_Telemetry::SlidersSet(int slider1, int slider2, int slider3, int slider4)
{
    Sliders.Data.sliders[0]=slider1;
    Sliders.Data.sliders[1]=slider2;
    Sliders.Data.sliders[2]=slider3;
    Sliders.Data.sliders[3]=slider4;
    regWrite(SLIDERS_BASEADDRESS,Sliders.buffer,sizeof(Sliders.buffer));
}


void SPI_Telemetry::IMP_ReadSw(float *pos, float *q)
{
    regReadSw(IMP_BASEADDRESS,IMP.buffer,sizeof(IMP.buffer));
    pos[0]=IMP.Data.Pos[0];
    pos[1]=IMP.Data.Pos[1];
    pos[2]=IMP.Data.Pos[2];
    q[0]=IMP.Data.q[0];
    q[1]=IMP.Data.q[1];
    q[2]=IMP.Data.q[2];
    q[3]=IMP.Data.q[3];
}

void SPI_Telemetry::IMU_ReadSw(int32_t *a, int32_t *g, int32_t *m)
{
    regReadSw(IMU_BASEADDRESS,IMU.buffer,sizeof(IMU.buffer));
    a[0]=IMU.Data.a[0];
    a[1]=IMU.Data.a[1];
    a[2]=IMU.Data.a[2];
    g[0]=IMU.Data.g[0];
    g[1]=IMU.Data.g[1];
    g[2]=IMU.Data.g[2];
    m[0]=IMU.Data.m[0];
    m[1]=IMU.Data.m[1];
    m[2]=IMU.Data.m[2];
}

void SPI_Telemetry::RPUs_ReadSw(int32_t *encoders, int32_t *forces)
{
    regReadSw(RPUs_BASEADDRESS,RPUs.buffer,sizeof(RPUs.buffer));
    encoders[0]=RPUs.Data.Enc[0];
    encoders[1]=RPUs.Data.Enc[1];
    encoders[2]=RPUs.Data.Enc[2];
    encoders[3]=RPUs.Data.Enc[3];
    forces[0]=RPUs.Data.force[0];
    forces[1]=RPUs.Data.force[1];
    forces[2]=RPUs.Data.force[2];
    forces[3]=RPUs.Data.force[3];
}

void SPI_Telemetry::Keys_SetSw(int key1, int key2, int key3, int key4)
{
    KEYs.Data.Keys[0]=key1;
    KEYs.Data.Keys[1]=key2;
    KEYs.Data.Keys[2]=key3;
    KEYs.Data.Keys[3]=key4;
    regWriteSw(KYES_BASEADDRESS,KEYs.buffer,sizeof(KEYs.buffer));
}

void SPI_Telemetry::SlidersSetSw(int slider1, int slider2, int slider3, int slider4)
{
    Sliders.Data.sliders[0]=slider1;
    Sliders.Data.sliders[1]=slider2;
    Sliders.Data.sliders[2]=slider3;
    Sliders.Data.sliders[3]=slider4;
    regWriteSw(SLIDERS_BASEADDRESS,Sliders.buffer,sizeof(Sliders.buffer));
}




void SPI_Telemetry::regRead(uint8_t Address, uint8_t *data, int len)
{
    uint8_t rxBuf[len+1];
    uint8_t txBuf[len+1];
    struct spi_ioc_transfer transfer;
    memset(&transfer, 0, sizeof(transfer));
    memset(&rxBuf, 0, sizeof(rxBuf));
    memset(&txBuf, 0, sizeof(txBuf));

    txBuf[0]=((uint8_t)(1<<7))|Address;
    transfer.tx_buf = (unsigned long) txBuf;
    transfer.rx_buf = (unsigned long) rxBuf;
    transfer.len = len+1;
    transfer.speed_hz = spiCLK;
    transfer.bits_per_word = 8;
    transfer.delay_usecs = 50;
    int status = ioctl(spiFD, SPI_IOC_MESSAGE(1), &transfer);
    if(status<0)
        qDebug() << "Coud not write to Regs" << status;
    memcpy((uint8_t *)data,(uint8_t *)&rxBuf[1],len);
}


void SPI_Telemetry::regWrite(uint8_t Address,uint8_t *data,int len)
{
    struct spi_ioc_transfer transfer;
    memset(&transfer, 0, sizeof(transfer));
    uint8_t txBuf[len+1];
    uint8_t rec[len+1];
    txBuf[0]=Address&0x7F;
    memcpy(&txBuf[1],data,len);
    transfer.tx_buf = (unsigned long) txBuf;
    transfer.rx_buf = (unsigned long) rec;
    transfer.len = len+1;
    transfer.speed_hz = spiCLK;
    transfer.bits_per_word = 8;
    transfer.delay_usecs = 50;
    int status = ioctl(spiFD, SPI_IOC_MESSAGE(1), &transfer);
    if(status<0)
        qDebug() << "Coud not write to Regs" << status;
}

void SPI_Telemetry::transaction(uint8_t *txBuff,uint8_t *rxBuff,int len)
{
    struct spi_ioc_transfer transfer;
    memset(&transfer, 0, sizeof(transfer));

    transfer.tx_buf = (unsigned long) txBuff;
    transfer.rx_buf = (unsigned long) rxBuff;
    transfer.len = len;
    transfer.speed_hz = spiCLK;
    transfer.bits_per_word = 8;
    transfer.delay_usecs = 0;
    int status = ioctl(spiFD, SPI_IOC_MESSAGE(1), &transfer);
    if(status<0)
        qDebug() << "Coud not write to Regs" << status;

}

void SPI_Telemetry::regReadSw(uint8_t Address, uint8_t *data, int len)
{
    memcpy((uint8_t *)data,(uint8_t *)&spi_rxBuff[Address],len);
}


void SPI_Telemetry::regWriteSw(uint8_t Address,uint8_t *data,int len)
{
   memcpy((uint8_t*)&spi_txBuff[Address],data,len);
}
    void SPI_Telemetry::updateTransaction(void)
    {

    transaction(spi_txBuff,spi_rxBuff,sizeof(spi_txBuff));
}

