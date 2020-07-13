/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：可移动按钮窗口
 * ***************************************/
#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H

#include <QWidget>

namespace Ui {
class MoveWidget;
}

class MoveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MoveWidget(QWidget *parent = 0);
    ~MoveWidget();

private:
    Ui::MoveWidget *ui;
    bool eventFilter(QObject *watched, QEvent *event);
    void createButton(const QPoint &buttonPos);
};

#endif // MOVEWIDGET_H
