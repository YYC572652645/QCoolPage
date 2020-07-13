/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板窗口
 * ***************************************/
#ifndef FRAMEWIDGET_H
#define FRAMEWIDGET_H

#include <QWidget>

class FlowLayout;

namespace Ui {
class FrameWidget;
}

class FrameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FrameWidget(QWidget *parent = 0);
    ~FrameWidget();

private:
    Ui::FrameWidget *ui;
    FlowLayout *flowLayout;
private:
    const QString IMAGE_PATH = ":/res/res/image/image.png";
private:
    void initValue();
};

#endif // FRAMEWIDGET_H
