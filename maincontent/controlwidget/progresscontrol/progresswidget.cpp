/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：进度条窗口
 * ***************************************/
#include "progresswidget.h"
#include "ui_progresswidget.h"

// 构造函数
ProgressWidget::ProgressWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
ProgressWidget::~ProgressWidget()
{
    delete ui;
}

// 初始化数据
void ProgressWidget::initValue()
{
    myTimer = new QTimer(this);
    myTimer->setInterval(1000);
    myTimer->start();

   connect(myTimer, SIGNAL(timeout()), this, SLOT(updateProgress()));
}

// 更新进度条
void ProgressWidget::updateProgress()
{
    static bool showFlage = false;
    if (!showFlage) {
        ui->widgetFirst->setPaintColor(Qt::white);
        ui->widgetFirst->setProgressValue(100);

        ui->widgetSecond->setPaintColor(Qt::cyan);
        ui->widgetSecond->setProgressValue(100);

        ui->widgetThird->setPaintColor(Qt::darkRed);
        ui->widgetThird->setProgressValue(100);

        ui->widgetFourth->setPaintColor(Qt::darkGreen);
        ui->widgetFourth->setProgressValue(100);

        ui->widgetFifth->setPaintColor(Qt::darkCyan);
        ui->widgetFifth->setProgressValue(100);

        ui->widgetSixth->setPaintColor(Qt::yellow);
        ui->widgetSixth->setProgressValue(100);
        showFlage = true;
    } else {
        ui->widgetFirst->setPaintColor(Qt::white);
        ui->widgetFirst->setProgressValue(0);

        ui->widgetSecond->setPaintColor(Qt::cyan);
        ui->widgetSecond->setProgressValue(0);

        ui->widgetThird->setPaintColor(Qt::darkRed);
        ui->widgetThird->setProgressValue(0);

        ui->widgetFourth->setPaintColor(Qt::darkGreen);
        ui->widgetFourth->setProgressValue(0);

        ui->widgetFifth->setPaintColor(Qt::darkCyan);
        ui->widgetFifth->setProgressValue(0);

        ui->widgetSixth->setPaintColor(Qt::yellow);
        ui->widgetSixth->setProgressValue(0);
        showFlage = false;
    }
}
