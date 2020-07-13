/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：坐标系
 * ***************************************/
#ifndef PLOTCONTROL_H
#define PLOTCONTROL_H

#include <QWidget>
#include <QVector>

#define LIN_COLOR  QColor(0, 107, 176)
#define TEXT_COLOR QColor(255, 255, 255)
#define BACKGROUND_COLOR QColor(26, 26, 26)
#define BRUSH_COLOR QColor(255, 255, 255, 0)
#define LABEL_COLOR QColor(40,150,120)


namespace Ui {
class PlotControl;
}

typedef struct CoorData
{
    QVector<double>dataX;  //横坐标
    QVector<double>dataY;  //纵坐标
}CoorData;

class PlotControl : public QWidget
{
    Q_OBJECT

    enum PointType {
        DATA_POINT = 0,
        SMALL_POINT,
        BIG_POINT,
    };

public:
    explicit PlotControl(QWidget *parent = 0);
    ~PlotControl();
    void setControlData(const CoorData &coorData);
private:
    Ui::PlotControl *ui;
    CoorData pointData;

private:
    void initValue();
    bool eventFilter(QObject *watched, QEvent *event) override;
    QPoint matchPoint(QPoint point);
};

#endif // PLOTCONTROL_H
