#ifndef PROGRESSWIDGET_H
#define PROGRESSWIDGET_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class ProgressWidget;
}

class ProgressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressWidget(QWidget *parent = 0);
    ~ProgressWidget();

private:
    Ui::ProgressWidget *ui;
    void paintImage(QWidget *paintWidget, float progressValue, Qt::GlobalColor paintColor = Qt::white);
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // PROGRESSWIDGET_H
