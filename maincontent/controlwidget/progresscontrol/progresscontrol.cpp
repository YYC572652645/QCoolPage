/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：进度条
 * ***************************************/
#include "progresscontrol.h"
#include "ui_progresscontrol.h"
#include <QDebug>

// 构造函数
ProgressControl::ProgressControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressControl)
{
    ui->setupUi(this);
}

// 析构函数
ProgressControl::~ProgressControl()
{
    delete ui;
}

// 设置进度条进度
void ProgressControl::setProgressValue(int value)
{
    while (progressValue < value)
    {
        progressValue += 0.1;
        qApp->processEvents();
        this->repaint();
    }
    progressValue = value;
    this->repaint();
}

// 设置进度条颜色
void ProgressControl::setPaintColor(const QColor &value)
{
    paintColor = value;
}

// 设置进度条100%
void ProgressControl::setProgressFinish()
{
    progressValue = 100;
}

// 绘制事件
void ProgressControl::paintEvent(QPaintEvent *paintEvent)
{
    Q_UNUSED(paintEvent);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font(QString("微软雅黑"));
    QPen painterPen;
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    QBrush brush(QColor(100, 100, 100, 255));
    painter.setBrush(brush);

    int widgetWidth = this->width();
    int widgetHeight = this->height();
    const int xRadius = 5;
    const int yRadius = 8;
    const int progressHeight = 10;
    const int offsetValue = 70;
    const int startDrawX = widgetWidth * 0.1;
    const int startDrawY = widgetHeight * 0.4;
    painter.drawRoundedRect(startDrawX, startDrawY, (widgetWidth - offsetValue * 2), progressHeight, xRadius, yRadius);

    //进度
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    if(progressValue != 0)
    {
        QBrush brush(paintColor);
        painter.setBrush(brush);
        painter.drawRoundedRect(startDrawX, startDrawY, (widgetWidth - offsetValue * 2) * progressValue / 100 , progressHeight, xRadius, yRadius);
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
