#ifndef MOVECONTROL_H
#define MOVECONTROL_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class MoveControl;
}

class MoveControl : public QWidget
{
    Q_OBJECT

public:
    explicit MoveControl(QWidget *parent = 0);
    ~MoveControl();

private slots:
    void on_pushButtonCloseControl_clicked();

private:
    Ui::MoveControl *ui;
    void initValue();
private:
    bool mousePress = false;
    QPoint movePoint = QPoint(0, 0);
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;
};

#endif // MOVECONTROL_H
