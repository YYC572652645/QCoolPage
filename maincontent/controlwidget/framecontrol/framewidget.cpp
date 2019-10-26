#include "framewidget.h"
#include "ui_framewidget.h"
#include "flowlayout/flowlayout.h"
#include "framecontrol.h"

FrameWidget::FrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameWidget)
{
    ui->setupUi(this);
    this->initValue();
}

FrameWidget::~FrameWidget()
{
    delete ui;
}

void FrameWidget::initValue()
{
    flowLayout = new FlowLayout(ui->scrollAreaWidgetContents);

    for (int i = 0; i < 100; i++) {
        FrameControl *frameControl = new FrameControl();
        frameControl->createFrame(QPixmap(IMAGE_PATH), tr("应用"));
        flowLayout->addWidget(frameControl);
    }
}
