#include "plotwidget.h"
#include "ui_plotwidget.h"

PlotWidget::PlotWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotWidget)
{
    ui->setupUi(this);
    this->initValue();
}

PlotWidget::~PlotWidget()
{
    delete ui;
}

void PlotWidget::initValue()
{
    const int MAX_YVALUE = 10;
    const int MAX_XVALUE = 100;
    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++) {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetFirst->setControlData(coorData);
    }

    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++) {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetSecond->setControlData(coorData);
    }

    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++) {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetThird->setControlData(coorData);
    }

    {
        CoorData coorData;
        for (int i = 0; i < MAX_XVALUE; i++) {
            coorData.dataX.append(i);
            int number = qrand() % MAX_YVALUE;
            coorData.dataY.append(number);
        }
        ui->widgetFourth->setControlData(coorData);
    }
}
