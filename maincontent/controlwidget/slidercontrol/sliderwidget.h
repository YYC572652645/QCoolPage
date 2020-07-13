/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：移动进度窗口
 * ***************************************/
#ifndef SLIDERWIDGET_H
#define SLIDERWIDGET_H

#include <QWidget>

namespace Ui {
class SliderWidget;
}

class SliderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SliderWidget(QWidget *parent = 0);
    ~SliderWidget();

private:
    Ui::SliderWidget *ui;
    void initValue();
};

#endif // SLIDERWIDGET_H
