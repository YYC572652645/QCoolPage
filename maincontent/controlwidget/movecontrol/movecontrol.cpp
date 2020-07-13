/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：可移动按钮
 * ***************************************/
#include "movecontrol.h"
#include "ui_movecontrol.h"

// 构造函数
MoveControl::MoveControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoveControl)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
MoveControl::~MoveControl()
{
    delete ui;
}

// 初始化
void MoveControl::initValue()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

// 鼠标点击事件
void MoveControl::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    movePoint = event->globalPos() - this->pos();
}

// 鼠标释放事件
void MoveControl::mouseReleaseEvent(QMouseEvent *)
{
    mousePress = false;
}

// 鼠标移动事件
void MoveControl::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePress)
    {
        QPoint movePos = event->globalPos();
        this->move(movePos - movePoint);
    }
}

// 按键移动事件
void MoveControl::keyPressEvent(QKeyEvent *keyEvent)
{
    const int keyMoveDis = 2;
    if (keyEvent->key() == Qt::Key_Up)
    {
        this->move(this->x(), this->y() - keyMoveDis);
    }
    else if (keyEvent->key() == Qt::Key_Down)
    {
        this->move(this->x(), this->y() + keyMoveDis);
    }
    else if (keyEvent->key() == Qt::Key_Left)
    {
        this->move(this->x() - keyMoveDis, this->y());
    }
    else if (keyEvent->key() == Qt::Key_Right)
    {
        this->move(this->x() + keyMoveDis, this->y());
    }
}

// 关闭当前窗口
void MoveControl::on_pushButtonCloseControl_clicked()
{
    this->close();
}
