#include "movewidget.h"
#include "ui_movewidget.h"
#include "movecontrol.h"
#include <QDebug>

MoveWidget::MoveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoveWidget)
{
    ui->setupUi(this);
    ui->frameBackground->installEventFilter(this);
}

MoveWidget::~MoveWidget()
{
    delete ui;
}

bool MoveWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->frameBackground && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent != nullptr)
        {
            this->createButton(mouseEvent->pos());
        }
    }
    return QWidget::eventFilter(watched, event);
}

void MoveWidget::createButton(const QPoint &buttonPos)
{
    MoveControl *moveControl = new MoveControl(this);
    int pointX = buttonPos.x() - moveControl->width() / 2;
    int pointY = buttonPos.y() - moveControl->height() / 2;

    moveControl->move(pointX, pointY);
    moveControl->setFocus();
    moveControl->show();
}
