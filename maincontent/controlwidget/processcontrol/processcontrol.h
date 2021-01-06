/*****************************************
 * 作者: YYC
 * 日期: 2021-01-06
 * 功能：流程进度控件，使用双向链表思想
 * ***************************************/
#ifndef PROCESSCONTROL_H
#define PROCESSCONTROL_H

#include <QWidget>
#include <QMap>
#include <QMouseEvent>

namespace Ui {
class ProcessControl;
}

class ProcessControl : public QWidget
{
    Q_OBJECT

public:
    enum ModeType
    {
        TYPE_ERROR,
        TYPE_NORMAL,
        TYPE_SUCCESS,
        TYPE_MAX,
    };
    explicit ProcessControl(QWidget *parent = 0);
    ~ProcessControl();
    QPoint getLeftCenter();
    QPoint getRightCenter();
    void switchMode(ModeType modeType);
    void setNextWidget(ProcessControl *value);
    ProcessControl *getNextWidget() const;
    void setPreWidget(ProcessControl *value);
    ProcessControl *getPreWidget() const;

private:
    void initValue();
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
private:
    Ui::ProcessControl *ui;
    bool mousePress = false;
    QPoint movePoint = QPoint(0, 0);
    ProcessControl *nextWidget = nullptr;
    ProcessControl *preWidget = nullptr;
    static QMap<int, QString> m_mapMode;
    static QMap<int, QColor> m_mapColor;
    const int OFFSET_VALEU = 10;
};

#endif // PROCESSCONTROL_H
