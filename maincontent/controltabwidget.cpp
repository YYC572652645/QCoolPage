#include "controltabwidget.h"
#include "ui_controltabwidget.h"

/******************   构造函数     *********************/
ControlTabWidget::ControlTabWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlTabWidget)
{
    ui->setupUi(this);
    this->initValue();
}

/******************   析构函数     *********************/
ControlTabWidget::~ControlTabWidget()
{
    delete ui;
}

/******************   初始化数据     *********************/
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
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabBanna;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_BANNA);
        mapTabWidget[TAB_BANNA] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabCylinder;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_CYLINDER);
        mapTabWidget[TAB_CYLINDER] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabProgress;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_PROGRESS);
        mapTabWidget[TAB_PROGRESS] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabFrame;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_FRAME);
        mapTabWidget[TAB_FRAME] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabPlot;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_CUSTOM_PLOT);
        mapTabWidget[TAB_CUSTOM_PLOT] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabMoveButton;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_MOVE_BUTTON);
        mapTabWidget[TAB_MOVE_BUTTON] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabTableWidget;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_TABLE_WIDGET);
        mapTabWidget[TAB_TABLE_WIDGET] = tabWidgetData;
    }

}

/******************   关闭当前页     *********************/
void ControlTabWidget::closeNowTab(int index)
{
    ui->tabWidgetControl->removeTab(index);
}

/******************   点击树形项显示对应Tab页     *********************/
void ControlTabWidget::receiveShowCurrentTab(WidgetTabType widgetTabType)
{
    if(widgetTabType >= TAB_MAX) return;
    TabWidgetData tabWidgetData = mapTabWidget.value(widgetTabType);
    if (ui->tabWidgetControl->indexOf(tabWidgetData.currentWidget) < 0) {
        ui->tabWidgetControl->addTab(tabWidgetData.currentWidget, tabWidgetData.currentTabText);
    }
    ui->tabWidgetControl->setCurrentWidget(tabWidgetData.currentWidget);
}

/******************   点击Tab页显示对应树形项     *********************/
void ControlTabWidget::on_tabWidgetControl_tabBarClicked(int index)
{
    for (auto iter = mapTabWidget.begin(); iter != mapTabWidget.end(); iter++)
    {
        QWidget *currentWidget = iter.value().currentWidget;
        if (currentWidget == ui->tabWidgetControl->widget(index))
        {
            emit sendShowIndex(iter.key());
        }
    }
}
