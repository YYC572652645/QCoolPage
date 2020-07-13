/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：封装了鼠标的一系列事件，用于鼠标移动窗口
 * 只需继承这个类，就能得到鼠标移动窗口的功能
 * ***************************************/
#include "titlebar.h"
#include <QDebug>

// 构造函数
TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    this->parentWidget = parent;
}

// 析构函数
void TitleBar::setParentWidget(QWidget *parentWidget)
{
    this->parentWidget = parentWidget;
}

// 鼠标点击事件
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    if(parentWidget)
    {
        movePoint = event->globalPos() - parentWidget->pos();
    }
}

// 鼠标释放事件
void TitleBar::mouseReleaseEvent(QMouseEvent *)
{
    mousePress = false;
}

// 鼠标移动事件
void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePress && parentWidget)
    {
        QPoint movePos = event->globalPos();
        parentWidget->move(movePos - movePoint);
    }
}
