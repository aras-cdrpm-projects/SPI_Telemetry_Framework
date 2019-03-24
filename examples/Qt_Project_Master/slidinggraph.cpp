#include "slidinggraph.h"


slidingGraph::slidingGraph(QObject *parent, QCustomPlot *plotObject)
{
    graph=plotObject;
    updateTimer= new QTimer(parent);
    signalList = new QList<double>;
    nameList   = new QList<QString>;
    signalList->clear();
    nameList->clear();
    numberOfGraphs=0;
    uEn=1;
    X_Scale=15;
    //Set the Background and Axis Clolors
    //Define the background color
    grad.setStart(0,0);
    grad.setFinalStop(0,350);
    grad.setColorAt(0, QColor(80, 80, 80));
    grad.setColorAt(1, QColor(10, 10, 10));
    //Set Background Color
    graph->setBackground(grad);
    graph->xAxis->setBasePen(QPen(Qt::white, 1));
    graph->yAxis->setBasePen(QPen(Qt::white, 1));
    graph->xAxis->setTickPen(QPen(Qt::white, 1));
    graph->yAxis->setTickPen(QPen(Qt::white, 1));
    //Set Axis color
    graph->xAxis->setSubTickPen(QPen(Qt::white, 1));
    graph->yAxis->setSubTickPen(QPen(Qt::white, 1));
    graph->xAxis->setTickLabelColor(Qt::white);
    graph->yAxis->setTickLabelColor(Qt::white);
    //Set grid colors
    graph->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    graph->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    graph->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    graph->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    graph->xAxis->grid()->setSubGridVisible(true);
    graph->yAxis->grid()->setSubGridVisible(true);
    graph->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    graph->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    graph->yAxis->setRange(-4, 4);
    //Add graph


    //start the Timers
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(reDrowGrapgh()));
    updateTimer->setInterval(20);
    updateTimer->start();

    elapsedTimer.start();
}

void slidingGraph::addGraph(QString name,QColor color)
{
    numberOfGraphs++;
    graph->addGraph();
    graph->graph(numberOfGraphs-1)->setPen(QPen(color));
    nameList->append(name);
    signalList->append(0);
}

void slidingGraph::removeGraph(QString name)
{
    numberOfGraphs--;
    graph->removeGraph(nameList->indexOf(name));
    signalList->removeAt(nameList->indexOf(name));
    nameList->removeOne(name);

}

void slidingGraph::addValue(QString name, double val)
{
    elapsedTime=(double)elapsedTimer.elapsed()/1000; //Elapsed Time in seconds
    graph->graph(nameList->indexOf(name))->addData(elapsedTime,val);  //Add new Data
    graph->graph(nameList->indexOf(name))->data().data()->removeBefore(elapsedTime-X_Scale);//remove old Data
}

void slidingGraph::setTimeScale(double scale)
{
    X_Scale=scale;
}

double slidingGraph::getTimeScale()
{
    return X_Scale;
}

void slidingGraph::setFrameRate(double frequency)
{
    double delay=1000.0/frequency;
    updateTimer->setInterval(delay);
}

void slidingGraph::setRange(double min, double max)
{
    graph->yAxis->setRange(min,max);
}

void slidingGraph::clearGraph()
{
    for(int i=0;i<numberOfGraphs;i++){
        graph->graph(i)->data().data()->clear();
        elapsedTimer.restart();
    }

}

void slidingGraph::updateEnable()
{
    uEn=1;

}

void slidingGraph::updateDisable()
{
    uEn=0;
}

void slidingGraph::reDrowGrapgh()
{
    elapsedTime=(double)elapsedTimer.elapsed()/1000; //Elapsed Time in seconds

    graph->xAxis->setRange(elapsedTime,X_Scale,Qt::AlignRight); //Scroll the plot
    if(uEn)
    graph->replot();//Update the plot

    emit graphUpdated();
}
