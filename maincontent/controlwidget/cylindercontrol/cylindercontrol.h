/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：柱状图
 * ***************************************/
#ifndef CYLINDERCONTROL_H
#define CYLINDERCONTROL_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class CylinderControl;
}

class CylinderControl : public QWidget
{
    Q_OBJECT

public:
    explicit CylinderControl(QWidget *parent = 0);
    ~CylinderControl();

    void setSliderValue(float value);
    void setSliderText(const QString &value);

private:
    Ui::CylinderControl *ui;
    float sliderValue = 0;
    QString sliderText;
private:
    void paintEvent(QPaintEvent *paintEvent) override;
};

#endif // CYLINDERCONTROL_H
