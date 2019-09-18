#ifndef FRAMECONTROL_H
#define FRAMECONTROL_H

#include <QWidget>

namespace Ui {
class FrameControl;
}

class FrameControl : public QWidget
{
    Q_OBJECT

public:
    explicit FrameControl(QWidget *parent = 0);
    ~FrameControl();

private:
    Ui::FrameControl *ui;
};

#endif // FRAMECONTROL_H
