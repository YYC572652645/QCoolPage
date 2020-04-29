/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：自制数字变化动画，根据设置开始和结束数字
 * 以及动画持续时间，来进行对数字的动态改变
 * ***************************************/

#ifndef NUMBERANIMATION_H
#define NUMBERANIMATION_H

#include <QWidget>
#include <QTimer>
#include <QVariant>

class NumberAnimation : public QObject
{
    Q_OBJECT
public:
    explicit NumberAnimation(QWidget *parent, double *targetValue);
    void setDuration(int msecs);
    void setStartValue(const QVariant &value);
    void setEndValue(const QVariant &value);
    void start(const QVariant &startValue, const QVariant &endValue);
    void start();
    void stop();
    void setLoopFlage(bool loopFlage);

public slots:
    void updateTimer();
private:
    QTimer m_numerTimer;
    QVariant m_startValue;
    QVariant m_endValue;
    QWidget *m_parentWidget;
    bool m_loopFlage;
    int m_duration;
    double *m_targetValue;
    double m_averageValue;
private:
    void incrementByClockwise(bool clockFlage);
};

#endif // NUMBERANIMATION_H
