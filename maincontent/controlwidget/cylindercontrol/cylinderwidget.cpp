#include "cylinderwidget.h"
#include "ui_cylinderwidget.h"
#include <QLinearGradient>
#include <QPainter>

CylinderWidget::CylinderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CylinderWidget)
{
    ui->setupUi(this);
    this->initValue();
}

CylinderWidget::~CylinderWidget()
{
    delete ui;
}

void CylinderWidget::initValue()
{
    ui->widgetFirst->setSliderValue(15);
    ui->widgetFirst->setSliderText("柱状图一");

    ui->widgetSecond->setSliderValue(30);
    ui->widgetSecond->setSliderText("柱状图二");

    ui->widgetThird->setSliderValue(45);
    ui->widgetThird->setSliderText("柱状图三");

    ui->widgetFourth->setSliderValue(60);
    ui->widgetFourth->setSliderText("柱状图四");

    ui->widgetFifth->setSliderValue(80);
    ui->widgetFifth->setSliderText("柱状图五");

    ui->widgetSixth->setSliderValue(95);
    ui->widgetSixth->setSliderText("柱状图六");
}
