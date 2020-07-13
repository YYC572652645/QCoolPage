/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：进度条
 * ***************************************/
#ifndef PROGRESSCONTROL_H
#define PROGRESSCONTROL_H

#include <QWidget>
#include <QPainter>
#include <QPen>

namespace Ui {
class ProgressControl;
}

class ProgressControl : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressControl(QWidget *parent = 0);
    ~ProgressControl();

    void setProgressValue(int value);
    void setPaintColor(const QColor &value);
    void setProgressFinish();

private:
    Ui::ProgressControl *ui;
    float progressValue = 0;
    QColor paintColor = QColor(Qt::white);
private:
    void paintEvent(QPaintEvent *paintEvent) override;
};

#endif // PROGRESSCONTROL_H
