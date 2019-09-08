#include "systemtray.h"
#include "globaldef.hpp"
#include <QDebug>
#include <QIcon>

SystemTray::SystemTray(QWidget * parent)
    :QSystemTrayIcon(parent)
{
    this->createAction();  //创建托盘菜单
    this->addAction();     //菜单添加事件

}

SystemTray::~SystemTray()
{

}

void SystemTray::addAction()
{
    myMenu->addAction(showWidget);
    myMenu->addAction(minWidget);
    myMenu->addAction(aboutSoftWare);
    myMenu->addAction(exitSoftWare);
}

void SystemTray::createAction()
{
    myMenu = new QMenu();
    showWidget = new QAction(tr("显示窗口 "), this);
    minWidget = new QAction(tr("隐藏窗口 "), this);
    aboutSoftWare = new QAction(tr("关于软件 "), this);
    exitSoftWare = new QAction(tr("退出软件 "), this);

    this->setIcon(QIcon(GlobalSpace::LOGO_PATH));
    this->setToolTip(tr("QCoolPage"));

    connect(exitSoftWare, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    this->setContextMenu(myMenu);
    this->show();
}

QAction *SystemTray::getAboutSoftWare() const
{
    return aboutSoftWare;
}

QAction *SystemTray::getMinWidget() const
{
    return minWidget;
}

QAction *SystemTray::getShowWidget() const
{
    return showWidget;
}
