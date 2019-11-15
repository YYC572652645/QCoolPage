#include "movecontrol.h"
#include "ui_movecontrol.h"

MoveControl::MoveControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoveControl)
{
    ui->setupUi(this);
    this->initValue();
}

MoveControl::~MoveControl()
{
    delete ui;
}

void MoveControl::initValue()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
}

void MoveControl::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    movePoint = event->globalPos() - this->pos();
}

void MoveControl::mouseReleaseEvent(QMouseEvent *)
{
    mousePress = false;
}

void MoveControl::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePress)
    {
        QPoint movePos = event->globalPos();
        this->move(movePos - movePoint);
    }
}

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

void MoveControl::on_pushButtonCloseControl_clicked()
{
    this->close();
}
