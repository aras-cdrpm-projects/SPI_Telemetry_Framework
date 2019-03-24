#ifndef SLIDINGGRAPH_H
#define SLIDINGGRAPH_H

#include <QObject>
#include "qcustomplot.h"
#include <QTimer>

class slidingGraph : public QObject
{
    Q_OBJECT
public:
    explicit slidingGraph(QObject *parent = nullptr,QCustomPlot *plotObject = nullptr);
    void addGraph(QString name,QColor color);
    void removeGraph(QString name);
    void addValue(QString name,double val);
    void setTimeScale(double scale);
    double getTimeScale(void);
    void setFrameRate(double frequency);
    void setRange(double min , double max);
    void clearGraph();
    void updateEnable();
    void updateDisable();

signals:
    void graphUpdated();

private slots:
    void reDrowGrapgh();
private:
    QTimer *updateTimer;
    QCustomPlot *graph;
    QLinearGradient grad;
    QElapsedTimer elapsedTimer;
    double X_Scale;
    double elapsedTime;
    int numberOfGraphs;
    QList<QString> *nameList;
    QList<double>  *signalList;
    int uEn;

};

#endif // SLIDINGGRAPH_H
