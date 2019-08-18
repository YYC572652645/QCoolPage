#include "progresswidget.h"
#include "ui_progresswidget.h"

ProgressWidget::ProgressWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressWidget)
{
    ui->setupUi(this);
    ui->widgetFirst->installEventFilter(this);
    ui->widgetSecond->installEventFilter(this);
    ui->widgetThird->installEventFilter(this);
    ui->widgetFourth->installEventFilter(this);
    ui->widgetFifth->installEventFilter(this);
    ui->widgetSixth->installEventFilter(this);
}

ProgressWidget::~ProgressWidget()
{
    delete ui;
}

void ProgressWidget::paintImage(QWidget *paintWidget, float progressValue, Qt::GlobalColor paintColor)
{
    if(nullptr == paintWidget) return;

    QPainter painter(paintWidget);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font(QString("微软雅黑"));
    QPen painterPen;
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    QBrush brush(QColor(100, 100, 100, 255));
    painter.setBrush(brush);

    int widgetWidth = paintWidget->rect().width();
    int widgetHeight = paintWidget->rect().height();
    const int xRadius = 5;
    const int yRadius = 8;
    const int progressHeight = 10;
    const int offsetValue = 70;
    const int startDrawX = widgetWidth * 0.1;
    const int startDrawY = widgetHeight * 0.4;
    painter.drawRoundedRect(startDrawX, startDrawY, (widgetWidth- offsetValue*2), progressHeight, xRadius, yRadius);

    //进度
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    if(progressValue != 0)
    {
        QBrush brush(paintColor);
        painter.setBrush(brush);
        painter.drawRoundedRect(startDrawX, startDrawY, (widgetWidth- offsetValue * 2) * progressValue / 100 , progressHeight, xRadius, yRadius);
    }

    //画百分比
    font.setPixelSize(14);
    font.setBold(false);
    painter.setFont(font);
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    painter.drawText(0, startDrawY, widgetWidth, 50, Qt::AlignCenter, QString::number(progressValue, 'f', 0) + QString("%"));
    painter.end();
}

bool ProgressWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->widgetFirst && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetFirst, 15, Qt::white);
    }
    else if(watched == ui->widgetSecond && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetSecond, 30, Qt::cyan);
    }
    else if(watched == ui->widgetThird && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetThird, 45, Qt::darkRed);
    }
    else if(watched == ui->widgetFourth && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetFourth, 60, Qt::darkGreen);
    }
    else if(watched == ui->widgetFifth && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetFifth, 80, Qt::darkCyan);
    }
    else if(watched == ui->widgetSixth && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetSixth, 95, Qt::yellow);
    }

    return QWidget::eventFilter(watched,event);
}
