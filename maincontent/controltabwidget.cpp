/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：界面右侧的TabWidget，显示当前已有的
 * 页面，与TreeWidget相对应
 * ***************************************/
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
    ui->tabWidgetControl->tabBar()->setHidden(true);

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
        tabWidgetData.currentWidget = ui->tabList;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_LIST);
        mapTabWidget[TAB_LIST] = tabWidgetData;
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


    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabSlider;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_SLIDER);
        mapTabWidget[TAB_SLIDER] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabProcess;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_PROCESS);
        mapTabWidget[TAB_PROCESS] = tabWidgetData;
    }

    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabOpengl;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_OPENGL);
        mapTabWidget[TAB_OPENGL] = tabWidgetData;
    }
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
