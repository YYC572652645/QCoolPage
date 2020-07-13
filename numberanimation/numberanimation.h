/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：自制数字变化动画，根据设置开始和结束数字
 * 以及动画持续时间，来进行对数字的动态改变
 * ***************************************/

#ifndef NUMBERANIMATION_H
#define NUMBERANIMATION_H

#include <QWidget>
#include <QBasicTimer>
#include <QVariant>
#include <QVariantAnimation>

class NumberAnimation : public QVariantAnimation
{
    Q_OBJECT
public:
    explicit NumberAnimation(QWidget *parent, double *targetValue);
    void startAnimation(const QVariant &startValue, const QVariant &endValue);
    void setLoopFlage(bool loopFlage);
private slots:
    void receiveValueChanged(const QVariant &value);
    void animationFinished();
private:
    void updateParentWidget();
private:
    QWidget *m_parentWidget;
    double *m_targetValue;
    bool m_loopFlage;
};

#endif // NUMBERANIMATION_H
