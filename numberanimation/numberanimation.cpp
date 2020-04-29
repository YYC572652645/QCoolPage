/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：自制数字变化动画，根据设置开始和结束数字
 * 以及动画持续时间，来进行对数字的动态改变
 * ***************************************/

#include "numberanimation.h"
#include <QDebug>

NumberAnimation::NumberAnimation(QWidget *parent, double *targetValue)
    : m_parentWidget(parent)
    , m_loopFlage(false)
    , m_duration(30)
    , m_targetValue(targetValue)
{
    m_numerTimer.setInterval(10);
    connect(&m_numerTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

void NumberAnimation::setDuration(int msecs)
{
    m_duration = msecs;
}

void NumberAnimation::setStartValue(const QVariant &value)
{
    m_startValue = value;
}

void NumberAnimation::setEndValue(const QVariant &value)
{
    m_endValue = value;
}

void NumberAnimation::start()
{
    if (m_numerTimer.isActive())
    {
        m_numerTimer.stop();
    }

    double distance = m_endValue.toDouble() - m_startValue.toDouble();
    m_averageValue = (distance) / m_duration;
    int interVal = static_cast<int>(m_averageValue / distance * m_duration);
    m_numerTimer.setInterval(interVal <= 0 ? 1 : interVal);
    m_numerTimer.start();
}

void NumberAnimation::stop()
{
    if (m_numerTimer.isActive())
    {
        m_numerTimer.stop();
    }
}

void NumberAnimation::start(const QVariant &startValue, const QVariant &endValue)
{
    this->setStartValue(startValue);
    this->setEndValue(endValue);
    this->start();
}

void NumberAnimation::updateTimer()
{
    if (m_targetValue != nullptr)
    {
        bool clockFlage = m_startValue < m_endValue;
        this->incrementByClockwise(clockFlage);

        if (nullptr != m_parentWidget)
        {
            m_parentWidget->repaint();
            m_parentWidget->update();
        }
    }
}

void NumberAnimation::setLoopFlage(bool loopFlage)
{
    m_loopFlage = loopFlage;
}

// true为顺时针增加，false为逆时针增加
void NumberAnimation::incrementByClockwise(bool clockFlage)
{
    double startValue = clockFlage ? *m_targetValue + m_averageValue : m_endValue.toDouble();
    double endValue = clockFlage ? m_endValue.toDouble() : *m_targetValue + m_averageValue;
    if (startValue <= endValue)
    {
        *m_targetValue += m_averageValue;
    }
    else
    {
        *m_targetValue = m_endValue.toInt();
        if (m_numerTimer.isActive())
        {
            m_numerTimer.stop();

            // 如果设置为可以循环，
            // 则动画以呼吸的方式来回变化
            // 增加 ->减少->增加->forever
            if (m_loopFlage)
            {
                double startValue = m_endValue.toDouble();
                double endValue = m_startValue.toDouble();
                this->start(startValue, endValue);
            }
        }
    }
}
