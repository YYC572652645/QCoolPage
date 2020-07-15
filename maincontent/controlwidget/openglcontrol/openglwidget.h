#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QWidget>

namespace Ui {
class OpenglWidget;
}

class OpenglWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OpenglWidget(QWidget *parent = 0);
    ~OpenglWidget();

private:
    Ui::OpenglWidget *ui;
};

#endif // OPENGLWIDGET_H
