/*****************************************
 * 作者: YYC
 * 日期: 2021-01-06
 * 功能：流程进度窗口，负责控件的创建，以及线的绘制
 * ***************************************/
#ifndef PROCESSWIDGET_H
#define PROCESSWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class ProcessControl;

namespace Ui {
class ProcessWidget;
}

class ProcessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessWidget(QWidget *parent = 0);
    ~ProcessWidget();

private:
    void initValue();
    QPoint getMidPoint(const QPoint &startPoint, const QPoint &endPoint);
    ProcessControl *createProcessControl();
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    Ui::ProcessWidget *ui;
    int m_modeType;
    ProcessControl *m_listHead = nullptr;
    const QPoint INIT_POINT = QPoint(20, 100);
    QMap<int, QColor> m_mapColor;
};

#endif // PROCESSWIDGET_H
