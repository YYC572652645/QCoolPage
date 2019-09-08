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
    void initValue();
};

#endif // CYLINDERWIDGET_H
