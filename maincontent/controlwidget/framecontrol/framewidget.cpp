/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板窗口
 * ***************************************/
#include "framewidget.h"
#include "ui_framewidget.h"
#include "flowlayout/flowlayout.h"
#include "framecontrol.h"

// 构造函数
FrameWidget::FrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
FrameWidget::~FrameWidget()
{
    delete ui;
}

// 初始化
void FrameWidget::initValue()
{
    flowLayout = new FlowLayout(ui->scrollAreaWidgetContents);

    for (int i = 0; i < 100; i++)
    {
        FrameControl *frameControl = new FrameControl();
        frameControl->createFrame(QPixmap(IMAGE_PATH), tr("应用"));
        flowLayout->addWidget(frameControl);
    }
}
