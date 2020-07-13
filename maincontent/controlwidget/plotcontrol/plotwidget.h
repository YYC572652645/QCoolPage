/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：坐标系窗口
 * ***************************************/
#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>

namespace Ui {
class PlotWidget;
}

class PlotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlotWidget(QWidget *parent = 0);
    ~PlotWidget();

private:
    Ui::PlotWidget *ui;
    void initValue();
};

#endif // PLOTWIDGET_H
