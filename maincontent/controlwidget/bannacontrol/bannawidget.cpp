#include "bannawidget.h"
#include "ui_bannawidget.h"

BannaWidget::BannaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BannaWidget)
{
    ui->setupUi(this);
}

BannaWidget::~BannaWidget()
{
    delete ui;
}
