/*****************************************
 * 作者: YYC
 * 日期: 2021-01-06
 * 功能：流程进度窗口，负责控件的创建，以及线的绘制
 * ***************************************/
#include "processwidget.h"
#include "ui_processwidget.h"
#include "processcontrol.h"
#include <QDebug>

// 构造函数
ProcessWidget::ProcessWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProcessWidget)
    , m_modeType(ProcessControl::TYPE_SUCCESS)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
ProcessWidget::~ProcessWidget()
{
    delete ui;
}

// 初始化数据
void ProcessWidget::initValue()
{
    ui->frameBackground->installEventFilter(this);
    const int MAX_CONTROL = 4;
    for (int i = 0; i < MAX_CONTROL; i++)
    {
        this->createProcessControl();
    }

    m_mapColor[ProcessControl::TYPE_ERROR] = QColor(153, 20, 20);
    m_mapColor[ProcessControl::TYPE_NORMAL] = QColor(255, 220, 220);
    m_mapColor[ProcessControl::TYPE_SUCCESS] = QColor(102, 153, 0);
}

// 获取两个点的中心点
QPoint ProcessWidget::getMidPoint(const QPoint &startPoint, const QPoint &endPoint)
{
    int midX = startPoint.x() + (endPoint.x() - startPoint.x()) / 2;
    int midY = startPoint.y() + (endPoint.y() - startPoint.y()) / 2;

    return QPoint(midX, midY);
}

// 创建控件，并自动加入双向链表
ProcessControl *ProcessWidget::createProcessControl()
{
    static ProcessControl *preWidget = nullptr;
    ProcessControl *processControl = new ProcessControl(this);
    processControl->switchMode(ProcessControl::ModeType(m_modeType));
    if (preWidget != nullptr)
    {
        preWidget->setNextWidget(processControl);
        processControl->setPreWidget(preWidget);

        const int OFFSET_VALUE = 40;
        QPoint rightCenter = preWidget->getRightCenter();
        rightCenter.setX(rightCenter.x() + OFFSET_VALUE);
        rightCenter.setY(rightCenter.y() + OFFSET_VALUE);
        processControl->move(rightCenter);
    }
    else
    {
        processControl->move(INIT_POINT);
        m_listHead = processControl;
    }
    preWidget = processControl;
    return processControl;
}

// 事件过滤
bool ProcessWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->frameBackground && event->type() == QEvent::Paint)
    {
        QPainter painter(ui->frameBackground);
        painter.setPen(QPen(m_mapColor.value(m_modeType), 1));

        ProcessControl *pHead = m_listHead;
        while (nullptr != pHead->getNextWidget())
        {
            int circleRadius = 5;
            QPoint startPoint = pHead->getRightCenter();
            QPoint endPoint = pHead->getNextWidget()->getLeftCenter();
            QPoint midPoint = this->getMidPoint(startPoint, endPoint);
            if (startPoint.y() > endPoint.y())
            {
                circleRadius = -circleRadius;
            }

            QPoint startRightPoint = QPoint(midPoint.x() - qAbs(circleRadius), startPoint.y());
            QPoint startRightNearPoint = QPoint(midPoint.x(), startPoint.y() + circleRadius);
            QPoint endLeftPoint = QPoint(midPoint.x() + qAbs(circleRadius), endPoint.y());
            QPoint endLeftNearPoint = QPoint(midPoint.x(), endPoint.y() - circleRadius);

            // 绘制拐角处的弧角
            {
                int startAngle = 0 * 16;
                int spanAngle = 90 * 16;

                int rectX = startRightPoint.x() - circleRadius;
                int rectY = startRightPoint.y();

                if (startPoint.y() > endPoint.y())
                {
                    rectX = startRightPoint.x() - qAbs(circleRadius);
                    rectY = startRightPoint.y() - qAbs(circleRadius) * 2;
                    startAngle = 270 * 16;
                }
                painter.drawArc(QRect(rectX, rectY, qAbs(circleRadius) * 2, qAbs(circleRadius) * 2), startAngle, spanAngle);

                startAngle = 180 * 16;
                rectX = endLeftNearPoint.x();
                rectY = endLeftNearPoint.y() - circleRadius;
                if (startPoint.y() > endPoint.y())
                {
                    rectX = endLeftPoint.x() - qAbs(circleRadius);
                    rectY = endLeftPoint.y();
                    startAngle = 90 * 16;
                }
                painter.drawArc(QRect(rectX, rectY, qAbs(circleRadius) * 2, qAbs(circleRadius) * 2), startAngle, spanAngle);

            }

            // 绘制直线
            {
                painter.drawLine(startPoint, startRightPoint);
                painter.drawLine(startRightNearPoint, endLeftNearPoint);
                painter.drawLine(endLeftPoint, endPoint);
            }
            pHead = pHead->getNextWidget();
        }
        painter.end();
    }
    return QWidget::eventFilter(watched, event);
}
