#ifndef BANNAWIDGET_H
#define BANNAWIDGET_H

#include <QWidget>

namespace Ui {
class BannaWidget;
}

class BannaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BannaWidget(QWidget *parent = 0);
    ~BannaWidget();

private:
    Ui::BannaWidget *ui;
};

#endif // BANNAWIDGET_H
