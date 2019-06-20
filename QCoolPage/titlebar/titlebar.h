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
