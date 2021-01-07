/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：移动进度
 * ***************************************/
#include "slidercontrol.h"
#include "ui_slidercontrol.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLinearGradient>
#include <QDebug>
#include "globaldef.hpp"
#include "numberanimation/numberanimation.h"

// 构造函数
SliderControl::SliderControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SliderControl)
    , m_currentIndex(-1)
    , m_currentLineWidth(0)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
SliderControl::~SliderControl()
{
    delete ui;
}

// 初始化数据
void SliderControl::initValue()
{
    ui->frameSlider->installEventFilter(this);
    this->m_currentIndex = MIDDLE_LABLE;

    QHBoxLayout *hboxLayout = new QHBoxLayout(ui->frameSlider);
    hboxLayout->addWidget(ui->pushButtonLeft);
    for (int i = 0; i < LABEL_NUMBER; i++)
    {
        QLabel *labelCircle = new QLabel(this);
        QPixmap circlePix;
        if (i == MIDDLE_LABLE)
        {
            circlePix = QPixmap(CENTER_CYAN_CIRCLE_PATH);
        }
        else
        {
            circlePix = QPixmap(SMALL_GRAY_CIRCLE_PATH);
        }
        labelCircle->setFixedSize(circlePix.size());
        labelCircle->setPixmap(circlePix);
        hboxLayout->addWidget(labelCircle);
    }
    hboxLayout->addWidget(ui->pushButtonRight);

    // 设置渐变动画
    m_numberAnimation = new NumberAnimation(this, &m_currentLineWidth);
}

void SliderControl::drawEvent()
{
    QPainter painter(ui->frameSlider);

    QPoint centerStartPos = GlobalSpace::GetCenterPosition(ui->pushButtonLeft);
    int centerStartX = centerStartPos.x();
    int centerStartY = centerStartPos.y();

    QPoint centerEndPos = GlobalSpace::GetCenterPosition(ui->pushButtonRight);
    int centerEndX = centerEndPos.x();
    int centerEndY = centerEndPos.y();

    int lineWidth = centerEndX - centerStartX;
    int lineHeight = 2;

    //设置线性渐变
    QLinearGradient linerGradient = QLinearGradient(centerStartX, centerStartY, centerEndX, centerEndY);
    linerGradient.setColorAt(0.0, QColor(LINEAR_COLOR.red(), LINEAR_COLOR.green(), LINEAR_COLOR.blue(), 0));
    linerGradient.setColorAt(0.5, QColor(LINEAR_COLOR.red(), LINEAR_COLOR.green(), LINEAR_COLOR.blue(), 60));
    linerGradient.setColorAt(1.0, QColor(LINEAR_COLOR.red(), LINEAR_COLOR.green(), LINEAR_COLOR.blue(), 0));

    // 绘制底部渐变灰色虚线
    QBrush brush(linerGradient);
    painter.setBrush(brush);
    painter.setPen(QColor(0, 0, 0, 0));
    painter.drawRect(centerStartX, centerStartY - 1, lineWidth, lineHeight);

    // 绘制进度
    QList<int> centeXList = m_labelPointMap.keys();
    centerStartX = centeXList.at(MIDDLE_LABLE);
    painter.setBrush(PROGRESS_COLOR);
    painter.drawRect(centerStartX, centerStartY - 1, static_cast<int>(m_currentLineWidth), lineHeight);

    painter.end();
}

// 设置左右移动时，将灰色图标切换为蓝色图标
void SliderControl::setupSelectCircle()
{
    int indexCount = 0;
    for (auto iter = m_labelPointMap.begin(); iter != m_labelPointMap.end(); iter++)
    {
        if(indexCount == MIDDLE_LABLE)
        {
            indexCount++;
            continue;
        }
        QPixmap circlePix;
        if (this->m_currentIndex > MIDDLE_LABLE)
        {
            if (indexCount > MIDDLE_LABLE && indexCount <= this->m_currentIndex)
            {
                circlePix = QPixmap(SMALL_BLUE_CIRCLE_PATH);
            }
            else
            {
                circlePix = QPixmap(SMALL_GRAY_CIRCLE_PATH);
            }
        }
        else
        {
            if (indexCount < MIDDLE_LABLE && indexCount >= this->m_currentIndex)
            {
                circlePix = QPixmap(SMALL_BLUE_CIRCLE_PATH);
            }
            else
            {
                circlePix = QPixmap(SMALL_GRAY_CIRCLE_PATH);
            }
        }
        iter.value()->setFixedSize(circlePix.size());
        iter.value()->setPixmap(circlePix);
        indexCount++;
    }
}


// 计算画的线的长度，并使用动画的方式增加
void SliderControl::calculateLineWidth()
{
    double lastLineWidth = m_currentLineWidth;
    QList<int> centeXList = m_labelPointMap.keys();
    int centerStartX = centeXList.at(MIDDLE_LABLE);
    int centerEndX = centeXList.at(m_currentIndex);
    double currentLineWidth = centerEndX - centerStartX;
    m_numberAnimation->startAnimation(lastLineWidth, currentLineWidth);
}

// 搜集中心点的坐标存入MAP
void SliderControl::collectCentPoint()
{
    m_labelPointMap.clear();
    QList<QLabel*>listLabel = ui->frameSlider->findChildren<QLabel*>();
    for (QLabel *labelCircle : listLabel)
    {
        m_labelPointMap[GlobalSpace::GetCenterPosition(labelCircle).x()] = labelCircle;
    }
}

// 事件过滤
bool SliderControl::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->frameSlider && event->type() == QEvent::Paint)
    {
        this->drawEvent();
    }
    else if (watched == ui->frameSlider && event->type() == QEvent::Resize)
    {
        // 当窗口大小改变时，重新计算中心点位置
        // 并重新计算画的线的长度
        this->collectCentPoint();
        this->calculateLineWidth();
        this->repaint();
    }
    return QWidget::eventFilter(watched, event);
}

// 点击左侧按钮
void SliderControl::on_pushButtonLeft_clicked()
{
    if (this->m_currentIndex > 0)
    {
        this->m_currentIndex--;
        this->setupSelectCircle();
        this->calculateLineWidth();
    }
}

// 点击右侧按钮
void SliderControl::on_pushButtonRight_clicked()
{
    if (this->m_currentIndex < LABEL_NUMBER - 1)
    {
        this->m_currentIndex++;
        this->setupSelectCircle();
        this->calculateLineWidth();
    }
}
