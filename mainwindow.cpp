#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initValue();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initValue()
{
    ui->widgetTitle->setParentWidget(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->widgetTree, SIGNAL(sendShowIndex(WidgetTabType)), ui->widgetTab, SLOT(receiveShowCurrentTab(WidgetTabType)));
}


