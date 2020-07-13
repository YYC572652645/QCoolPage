/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：封装了鼠标的一系列事件，用于鼠标移动窗口
 * 只需继承这个类，就能得到鼠标移动窗口的功能
 * ***************************************/
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = 0);
    void setParentWidget(QWidget *parentWidget);
protected:
    bool mousePress = false;
    QPoint movePoint = QPoint(0, 0);
    QWidget *parentWidget = nullptr;
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // TITLEBAR_H
