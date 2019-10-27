#include "plotcontrol.h"
#include "ui_plotcontrol.h"

PlotControl::PlotControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotControl)
{
    ui->setupUi(this);
    this->initValue();
}

PlotControl::~PlotControl()
{
    delete ui;
}

void PlotControl::initValue()
{
    //可放大缩小
    ui->widgetCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // 设置背景色
    ui->widgetCustomPlot->setBackground(QBrush(BACKGROUND_COLOR));

    // 设置坐标轴颜色
    ui->widgetCustomPlot->xAxis->setTickLabelColor(TEXT_COLOR);
    ui->widgetCustomPlot->yAxis->setTickLabelColor(TEXT_COLOR);

    //设置1为固定的一个刻度
    ui->widgetCustomPlot->xAxis->setAutoTickStep(false);
    ui->widgetCustomPlot->xAxis->setTickStep(1);
    ui->widgetCustomPlot->xAxis->setSubTickCount(1);
    ui->widgetCustomPlot->yAxis->setAutoTickStep(false);
    ui->widgetCustomPlot->yAxis->setTickStep(1);
    ui->widgetCustomPlot->yAxis->setSubTickCount(1);

    //设置范围
    ui->widgetCustomPlot->xAxis->setRange(0, 10);
    ui->widgetCustomPlot->yAxis->setRange(0, 10);

    //第一个图
    ui->widgetCustomPlot->addGraph();

    //设置画笔
    QPen paintPen;
    paintPen.setColor(LIN_COLOR);
    ui->widgetCustomPlot->graph(0)->setPen(paintPen);
    ui->widgetCustomPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //设置第一个点
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(1)->setPen(QPen(Qt::darkRed));
    ui->widgetCustomPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->widgetCustomPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    //设置第二个点
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(2)->setPen(QPen(Qt::darkRed));
    ui->widgetCustomPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->widgetCustomPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 12));
}

void PlotControl::setControlData(const CoorData &coorData)
{
    ui->widgetCustomPlot->graph(0)->setData(coorData.dataX, coorData.dataY);
    ui->widgetCustomPlot->graph(1)->setData(coorData.dataX, coorData.dataY);
    ui->widgetCustomPlot->replot();
}
