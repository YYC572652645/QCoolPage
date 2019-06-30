#include "controltabwidget.h"
#include "ui_controltabwidget.h"

ControlTabWidget::ControlTabWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlTabWidget)
{
    ui->setupUi(this);
    this->initValue();
}

ControlTabWidget::~ControlTabWidget()
{
    delete ui;
}

void ControlTabWidget::initValue()
{
    ui->tabWidgetControl->setTabsClosable(true);
    connect(ui->tabWidgetControl, SIGNAL(tabCloseRequested(int)), this, SLOT(closeNowTab(int)));

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(30, 30, 30));
    ui->tabWidgetControl->setAutoFillBackground(true);
    ui->tabWidgetControl->setPalette(palette);
    ui->tabWidgetControl->tabBar()->setPalette(palette);

    {
        TabWidgetData tabWidgetText;
        tabWidgetText.currentWidget = ui->tabBanna;
        tabWidgetText.currentTabText = ui->tabWidgetControl->tabText(TAB_BANNA);
        mapTabWidget[TAB_BANNA] = tabWidgetText;
    }

}

void ControlTabWidget::closeNowTab(int index)
{
    ui->tabWidgetControl->removeTab(index);
}

void ControlTabWidget::receiveShowCurrentTab(WidgetTabType widgetTabType)
{
    if(widgetTabType >= TAB_MAX) return;
    TabWidgetData tabWidgetData = mapTabWidget.value(widgetTabType);
    ui->tabWidgetControl->addTab(tabWidgetData.currentWidget, tabWidgetData.currentTabText);
    ui->tabWidgetControl->setCurrentWidget(tabWidgetData.currentWidget);
}
