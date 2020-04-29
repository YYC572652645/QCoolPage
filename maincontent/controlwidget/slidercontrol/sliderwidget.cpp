#include "sliderwidget.h"
#include "ui_sliderwidget.h"
#include "slidercontrol.h"
#include <QVBoxLayout>

SliderWidget::SliderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SliderWidget)
{
    ui->setupUi(this);
    this->initValue();
}

SliderWidget::~SliderWidget()
{
    delete ui;
}

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
