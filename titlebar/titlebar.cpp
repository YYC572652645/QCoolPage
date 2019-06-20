#include "titlebar.h"
#include <QDebug>

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    this->parentWidget = parent;
}

void TitleBar::setParentWidget(QWidget *parentWidget)
{
    this->parentWidget = parentWidget;
}

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

void TitleBar::mouseReleaseEvent(QMouseEvent *)
{
    mousePress = false;
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePress && parentWidget)
    {
        QPoint movePos = event->globalPos();
        parentWidget->move(movePos - movePoint);
    }
}
