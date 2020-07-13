/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：坐标系窗口
 * ***************************************/
#include "plotwidget.h"
#include "ui_plotwidget.h"

// 构造函数
PlotWidget::PlotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
PlotWidget::~PlotWidget()
{
    delete ui;
}

// 初始化数据
void PlotWidget::initValue()
{
    const int MAX_YVALUE = 10;
    const int MAX_XVALUE = 100;
    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++)
        {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetFirst->setControlData(coorData);
    }

    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++)
        {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetSecond->setControlData(coorData);
    }

    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++)
        {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetThird->setControlData(coorData);
    }

    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++)
        {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetFourth->setControlData(coorData);
    }
}
