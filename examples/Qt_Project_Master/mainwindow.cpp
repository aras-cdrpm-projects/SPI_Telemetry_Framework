#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spi_telemetry.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spi_Tel = new SPI_Telemetry(this , 0, 500000);

    ui->quickWidget->setSource(QUrl::fromLocalFile("/opt/main.qml"));
    initQItem=ui->quickWidget->rootObject();
    sw1=initQItem->findChild<QObject *>("sw1");
    sw2=initQItem->findChild<QObject *>("sw2");
    sw3=initQItem->findChild<QObject *>("sw3");
    sw4=initQItem->findChild<QObject *>("sw4");
    slider1=initQItem->findChild<QObject *>("slider1");
    slider2=initQItem->findChild<QObject *>("slider2");
    slider3=initQItem->findChild<QObject *>("slider3");
    slider4=initQItem->findChild<QObject *>("slider4");

    imuGraph= new slidingGraph(this,ui->IMU_CHART);
    posGraph= new slidingGraph(this,ui->POS_CHART);
    imuGraph->addGraph(QString("Graph 1"),Qt::green);
    posGraph->addGraph(QString("Graph 1"),Qt::green);
    imuGraph->setFrameRate(15);
    posGraph->setFrameRate(15);
    posGraph->setRange(-5,5);
    imuGraph->updateEnable();
    posGraph->updateEnable();
    posGraph->addGraph(QString("X POS"),Qt::green);
    posGraph->addGraph(QString("Y POS"),Qt::yellow);
    posGraph->addGraph(QString("Z POS"),Qt::red);
    imuGraph->addGraph(QString("X"),Qt::green);
    imuGraph->addGraph(QString("Y"),Qt::yellow);
    imuGraph->addGraph(QString("Z"),Qt::red);
    //gauge Setings
    ui->FORCE_GAUGE->addBackground(99);
    QcBackgroundItem *bkg1 = ui->FORCE_GAUGE->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,Qt::black);
    bkg1->addColor(1.0,Qt::white);
    QcBackgroundItem *bkg2 = ui->FORCE_GAUGE->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::gray);
    bkg2->addColor(1.0,Qt::darkGray);
    ui->FORCE_GAUGE->addArc(55);
    ui->FORCE_GAUGE->addDegrees(65)->setValueRange(0,100);
    ui->FORCE_GAUGE->addColorBand(50);
    ui->FORCE_GAUGE->addValues(80)->setValueRange(0,100);
    ui->FORCE_GAUGE->addLabel(70)->setText("N");
    QcLabelItem *lab = ui->FORCE_GAUGE->addLabel(40);
    lab->setText("0");
    mGaugeNeedle = ui->FORCE_GAUGE->addNeedle(60);
    mGaugeNeedle->setLabel(lab);
    mGaugeNeedle->setColor(Qt::white);
    mGaugeNeedle->setValueRange(0,100);
    ui->FORCE_GAUGE->addBackground(7);
    ui->FORCE_GAUGE->addGlass(88);
    //Timers and signel connections
    IMUUpdateTimer.setInterval(10);
    IMPUpdateTimer.setInterval(10);
    RPUUpdateTimer.setInterval(20);
    transactionTimer.setInterval(10);
    connect(&IMUUpdateTimer,SIGNAL(timeout()),this,SLOT(updateIMUMonitors()));
    connect(&IMPUpdateTimer,SIGNAL(timeout()),this,SLOT(updateIMPMonitors()));
    connect(&RPUUpdateTimer,SIGNAL(timeout()),this,SLOT(updateRPUMonitors()));
    connect(&transactionTimer,SIGNAL(timeout()),this,SLOT(newTransaction()));
    IMUUpdateTimer.start();
    IMPUpdateTimer.start();
    RPUUpdateTimer.start();
    transactionTimer.start();
    switch(ui->IMU_SELECTOR->currentIndex())
    {
    case 0:
        imuGraph->setRange(-1000,1000);
        break;
    case 1:
        imuGraph->setRange(-16,16);
        break;
    case 2:
        imuGraph->setRange(-10,10);
        break;
    }
    ui->tabWidget->setCurrentIndex(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateIMPMonitors()
{
    float pos[3], q[4];
    spi_Tel->IMP_ReadSw(pos, q);
    ui->X_LCD->display(pos[0]);
    ui->Y_LCD->display(pos[1]);
    ui->Z_LCD->display(pos[2]);
    posGraph->addValue(QString("X POS"),pos[0]);
    posGraph->addValue(QString("Y POS"),pos[1]);
    posGraph->addValue(QString("Z POS"),pos[2]);
}

void MainWindow::updateRPUMonitors()
{
    int32_t encoders[4], forces[4];
    spi_Tel->RPUs_ReadSw(encoders, forces);
    switch(ui->FORCE_SELECTOR->currentIndex())
    {
    case 0:
        mGaugeNeedle->setCurrentValue(forces[0]);
        ui->FORCE_LCD->display(forces[0]);
        break;
    case 1:
        mGaugeNeedle->setCurrentValue(forces[1]);
        ui->FORCE_LCD->display(forces[1]);
        break;
    case 2:
        mGaugeNeedle->setCurrentValue(forces[2]);
        ui->FORCE_LCD->display(forces[2]);
        break;
    case 3:
        mGaugeNeedle->setCurrentValue(forces[3]);
        ui->FORCE_LCD->display(forces[3]);
        break;
    }
    ui->ENCODER1_LCD->display(encoders[0]);
    ui->ENCODER2_LCD->display(encoders[1]);
    ui->ENCODER3_LCD->display(encoders[2]);
    ui->ENCODER4_LCD->display(encoders[3]);
    int key1,key2,key3,key4;
    uint8_t sl1,sl2,sl3,sl4;
    key1=sw1->property("checked").toInt();
    key2=sw2->property("checked").toInt();
    key3=sw3->property("checked").toInt();
    key4=sw4->property("checked").toInt();
    spi_Tel->Keys_SetSw(key1,key2,key3,key4);
    sl1=(uint8_t)(slider1->property("value").toFloat()*255);
    sl2=(uint8_t)(slider2->property("value").toFloat()*255);
    sl3=(uint8_t)(slider3->property("value").toFloat()*255);
    sl4=(uint8_t)(slider4->property("value").toFloat()*255);
    spi_Tel->SlidersSetSw(sl1,sl2,sl3,sl4);
}

void MainWindow::updateIMUMonitors()
{
    int32_t a[3], g[3], m[3];
    spi_Tel->IMU_ReadSw(a, g, m);
    switch(ui->IMU_SELECTOR->currentIndex())
    {
    case 0:
        ui->IMU_X->display(a[0]);
        ui->IMU_Y->display(a[1]);
        ui->IMU_Z->display(a[2]);
        imuGraph->addValue(QString("X"),a[0]);
        imuGraph->addValue(QString("Y"),a[1]);
        imuGraph->addValue(QString("Z"),a[2]);
        break;
    case 1:
        ui->IMU_X->display(g[0]);
        ui->IMU_Y->display(g[1]);
        ui->IMU_Z->display(g[2]);
        imuGraph->addValue(QString("X"),g[0]);
        imuGraph->addValue(QString("Y"),g[1]);
        imuGraph->addValue(QString("Z"),g[2]);
        break;
    case 2:
        ui->IMU_X->display(m[0]);
        ui->IMU_Y->display(m[1]);
        ui->IMU_Z->display(m[2]);
        imuGraph->addValue(QString("X"),m[0]);
        imuGraph->addValue(QString("Y"),m[1]);
        imuGraph->addValue(QString("Z"),m[2]);
        break;
    }
}

void MainWindow::newTransaction()
{
    transactionTimer.stop();
    spi_Tel->updateTransaction();
    transactionTimer.start();

}

void MainWindow::switchClicked()
{
    qDebug() << "Clicked";

}

void MainWindow::on_IMU_SELECTOR_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        imuGraph->setRange(-1000,1000);
        break;
    case 1:
        imuGraph->setRange(-16,16);
        break;
    case 2:
        imuGraph->setRange(-10,10);
        break;
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==2)
        ui->FORCE_GAUGE->setFocus();
}
