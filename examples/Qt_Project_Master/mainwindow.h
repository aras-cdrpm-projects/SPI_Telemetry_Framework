#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QUdpSocket>
//#include "udptransmitter.h"
#include "qcgaugewidget.h"
//#include "serialtelemetry.h"
#include "slidinggraph.h"
#include <QQuickItem>
#include "spi_telemetry.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    //QThread transmitterTread;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateIMPMonitors();
    void updateRPUMonitors();
    void updateIMUMonitors();
    void newTransaction();
    void switchClicked();


    void on_IMU_SELECTOR_currentIndexChanged(int index);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QLinearGradient grad;
    QTimer IMPUpdateTimer,RPUUpdateTimer,IMUUpdateTimer,transactionTimer;
    QcNeedleItem *mGaugeNeedle;
    slidingGraph *imuGraph;
    slidingGraph *posGraph;
    SPI_Telemetry *spi_Tel;
    QQuickItem *initQItem;
    QObject *sw1;
    QObject *sw2;
    QObject *sw3;
    QObject *sw4;
    QObject *slider1;
    QObject *slider2;
    QObject *slider3;
    QObject *slider4;
};

#endif // MAINWINDOW_H
