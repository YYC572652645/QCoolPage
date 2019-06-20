#include "maintitlebar.h"
#include "ui_maintitlebar.h"

MainTitleBar::MainTitleBar(QWidget *parent) :
    TitleBar(parent),
    ui(new Ui::MainTitleBar)
{
    ui->setupUi(this);
    ui->widgetNormalMax->hide();
    ui->pushButtonMax->hide();
}

MainTitleBar::~MainTitleBar()
{
    delete ui;
}

void MainTitleBar::on_pushButtonClose_clicked()
{
    if(parentWidget)
    {
        parentWidget->close();
    }
}

void MainTitleBar::on_pushButtonMin_clicked()
{
    if(parentWidget)
    {
        parentWidget->showMinimized();
    }
}

void MainTitleBar::showNormalMax()
{
    if(parentWidget->windowState() != Qt::WindowMaximized)
    {
        parentWidget->showMaximized();
        ui->pushButtonMax->show();
        ui->pushButtonNormal->hide();

    }
    else
    {
        parentWidget->showNormal();
        ui->pushButtonMax->hide();
        ui->pushButtonNormal->show();
    }

    ui->pushButtonMax->repaint();
    ui->pushButtonNormal->repaint();
}

void MainTitleBar::on_pushButtonMax_clicked()
{
    this->showNormalMax();
}

void MainTitleBar::on_pushButtonNormal_clicked()
{
    this->showNormalMax();
}
