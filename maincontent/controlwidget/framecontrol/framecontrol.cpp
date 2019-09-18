#include "framecontrol.h"
#include "ui_framecontrol.h"

FrameControl::FrameControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameControl)
{
    ui->setupUi(this);
}

FrameControl::~FrameControl()
{
    delete ui;
}
