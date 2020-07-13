/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：移动进度窗口
 * ***************************************/
#include "sliderwidget.h"
#include "ui_sliderwidget.h"
#include "slidercontrol.h"
#include <QVBoxLayout>

// 构造函数
SliderWidget::SliderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SliderWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
SliderWidget::~SliderWidget()
{
    delete ui;
}

// 初始化数据
void SliderWidget::initValue()
{
    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    for (int i = 0; i < 5; i++)
    {
        SliderControl *sliderControl = new SliderControl(this);
        vboxLayout->addWidget(sliderControl);
    }
}
