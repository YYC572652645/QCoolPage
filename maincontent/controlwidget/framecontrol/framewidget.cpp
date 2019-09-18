#include "framewidget.h"
#include "ui_framewidget.h"

FrameWidget::FrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameWidget)
{
    ui->setupUi(this);
}

FrameWidget::~FrameWidget()
{
    delete ui;
}
