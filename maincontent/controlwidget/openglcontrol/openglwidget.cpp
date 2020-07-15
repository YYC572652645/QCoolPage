#include "openglwidget.h"
#include "ui_openglwidget.h"

OpenglWidget::OpenglWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenglWidget)
{
    ui->setupUi(this);
}

OpenglWidget::~OpenglWidget()
{
    delete ui;
}
