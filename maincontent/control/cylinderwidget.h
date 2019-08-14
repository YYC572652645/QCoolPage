#ifndef CYLINDERWIDGET_H
#define CYLINDERWIDGET_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class CylinderWidget;
}

class CylinderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CylinderWidget(QWidget *parent = 0);
    ~CylinderWidget();

private:
    Ui::CylinderWidget *ui;
    void paintImage(QWidget * widget, float sliderValue, QString text);
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // CYLINDERWIDGET_H
