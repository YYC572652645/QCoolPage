#include "qwatchdesigner.h"
#include "ui_qwatchdesigner.h"

QWatchDesigner::QWatchDesigner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWatchDesigner)
{
    ui->setupUi(this);
    this->initValue();
}

QWatchDesigner::~QWatchDesigner()
{
    delete ui;
}

void QWatchDesigner::initValue()
{
    ui->widgetTitle->setParentWidget(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);


}
