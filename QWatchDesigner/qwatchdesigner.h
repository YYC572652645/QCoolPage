#ifndef QWATCHDESIGNER_H
#define QWATCHDESIGNER_H

#include <QMainWindow>

namespace Ui {
class QWatchDesigner;
}

class QWatchDesigner : public QMainWindow
{
    Q_OBJECT

public:
    explicit QWatchDesigner(QWidget *parent = 0);
    ~QWatchDesigner();

private:
    Ui::QWatchDesigner *ui;
    void initValue();
};

#endif // QWATCHDESIGNER_H
