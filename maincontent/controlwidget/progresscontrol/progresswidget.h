/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：进度条窗口
 * ***************************************/
#ifndef PROGRESSWIDGET_H
#define PROGRESSWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

namespace Ui {
class ProgressWidget;
}

class ProgressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressWidget(QWidget *parent = 0);
    ~ProgressWidget();
private slots:
    void updateProgress();
private:
    Ui::ProgressWidget *ui;
    QTimer *myTimer;
private:
    void initValue();
};

#endif // PROGRESSWIDGET_H
