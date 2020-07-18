/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：最外层主窗体，绑定点击显示响应的页面之间
 * 的信号与槽，以及创建系统托盘
 * ***************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

// 构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
MainWindow::~MainWindow()
{
    delete ui;
}

// 初始化
void MainWindow::initValue()
{
    // 创建系统托盘
    syetemTray = new SystemTray(this);
    connect(syetemTray->getShowWidget(), SIGNAL(triggered(bool)), this, SLOT(showNormal()));
    connect(syetemTray->getMinWidget(), SIGNAL(triggered(bool)), this, SLOT(showMinimized()));
    ui->widgetTitle->setParentWidget(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 将TreeWidget点击的index与TabWidget页面显示的index相互绑定
    connect(ui->widgetTree, SIGNAL(sendShowIndex(WidgetTabType)), ui->widgetTab, SLOT(receiveShowCurrentTab(WidgetTabType)));
}


