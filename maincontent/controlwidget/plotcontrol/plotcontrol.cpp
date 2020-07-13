/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：坐标系
 * ***************************************/
#include "plotcontrol.h"
#include "ui_plotcontrol.h"
#include <QDebug>

// 构造函数
PlotControl::PlotControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotControl)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
PlotControl::~PlotControl()
{
    delete ui;
}

// 初始化
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

    //设置画笔
    QPen paintPen;
    paintPen.setColor(LIN_COLOR);
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(DATA_POINT)->setPen(paintPen);
    ui->widgetCustomPlot->graph(DATA_POINT)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //设置第一个点
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(SMALL_POINT)->setPen(QPen(Qt::darkRed));
    ui->widgetCustomPlot->graph(SMALL_POINT)->setLineStyle(QCPGraph::lsNone);
    ui->widgetCustomPlot->graph(SMALL_POINT)->setScatterStyle(QCPScatterStyle::ssDisc);

    //设置第二个点
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(BIG_POINT)->setPen(QPen(Qt::darkRed));
    ui->widgetCustomPlot->graph(BIG_POINT)->setLineStyle(QCPGraph::lsNone);
    ui->widgetCustomPlot->graph(BIG_POINT)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 12));

    // 注册监听事件
    ui->widgetCustomPlot->installEventFilter(this);
}

// 设置图表数据
void PlotControl::setControlData(const CoorData &coorData)
{
    pointData = coorData;
    ui->widgetCustomPlot->graph(DATA_POINT)->setData(coorData.dataX, coorData.dataY);
    ui->widgetCustomPlot->graph(SMALL_POINT)->setData(coorData.dataX, coorData.dataY);
    ui->widgetCustomPlot->replot();
}


// 鼠标移动
bool PlotControl::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->widgetCustomPlot && event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int xPos = mouseEvent->pos().x();
        int yPos = mouseEvent->pos().y();

        float xValue = ui->widgetCustomPlot->xAxis->pixelToCoord(xPos);
        float yValue = ui->widgetCustomPlot->yAxis->pixelToCoord(yPos);

        QPoint pointMatch = matchPoint(QPoint(xValue, yValue));

        CoorData bigPointData;
        bigPointData.dataX.append(pointMatch.x());
        bigPointData.dataY.append(pointMatch.y());

        ui->widgetCustomPlot->graph(BIG_POINT)->setData(bigPointData.dataX, bigPointData.dataY);
        ui->widgetCustomPlot->replot();
    }

    return QWidget::eventFilter(watched, event);
}

// 匹配距离当前鼠标最近的点
QPoint PlotControl::matchPoint(QPoint point)
{
    /******************************************
     * 思路：
     * 鼠标当前的点与实际坐标相比较，
     * 离哪个点比较近，返回当前比较近的点的坐标
     * *****************************************/

    QList<QPoint> pointList;
    QList<float> compareompareList;
    for(int i = 0; i < pointData.dataX.size(); i ++)
    {
        float diffValue = point.x() - pointData.dataX.at(i);
        if(diffValue > -1 && diffValue < 1)
        {
            pointList.append(QPoint(pointData.dataX.at(i), pointData.dataY.at(i)));

            compareompareList.append(std::abs(pointData.dataX.at(i) - point.x()));
        }
    }

    if(compareompareList.size() != 0)
    {
        int minIndex = 0;
        float minValue = compareompareList.at(0);
        for(int i = 0; i < compareompareList.size(); i ++)
        {
            if(compareompareList.at(i) < minValue)
            {
                minValue = compareompareList.at(i);
                minIndex = i;
            }
        }
        if (minIndex < pointList.size())
        {
            return pointList.at(minIndex);
        }
    }

    return QPoint(0, 0);
}
