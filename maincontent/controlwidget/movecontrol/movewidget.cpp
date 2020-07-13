/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：可移动按钮窗口
 * ***************************************/
#include "movewidget.h"
#include "ui_movewidget.h"
#include "movecontrol.h"
#include <QDebug>

// 构造函数
MoveWidget::MoveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoveWidget)
{
    ui->setupUi(this);
    ui->frameBackground->installEventFilter(this);
}

// 析构函数
MoveWidget::~MoveWidget()
{
    delete ui;
}

// 事件过滤
bool MoveWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->frameBackground && event->type() == QEvent::MouseButtonPress)
    {
        // 点击一下鼠标创建一个
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent != nullptr)
        {
            this->createButton(mouseEvent->pos());
        }
    }
    return QWidget::eventFilter(watched, event);
}

// 创建按钮，以中心点创建
void MoveWidget::createButton(const QPoint &buttonPos)
{
    MoveControl *moveControl = new MoveControl(this);
    int pointX = buttonPos.x() - moveControl->width() / 2;
    int pointY = buttonPos.y() - moveControl->height() / 2;

    moveControl->move(pointX, pointY);
    moveControl->setFocus();
    moveControl->show();
}
