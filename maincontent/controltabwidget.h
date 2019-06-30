#ifndef CONTROLTABWIDGET_H
#define CONTROLTABWIDGET_H

#include <QWidget>
#include "globaldef.hpp"
#include "control/bannawidget.h"

namespace Ui {
class ControlTabWidget;
}
typedef struct TabWidgetData
{
    QWidget *currentWidget;
    QString currentTabText;
}TabWidgetData;

using MapWidget = QMap<WidgetTabType, TabWidgetData>;

class ControlTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlTabWidget(QWidget *parent = 0);
    ~ControlTabWidget();

private slots:
    void closeNowTab(int index);
    void receiveShowCurrentTab(WidgetTabType widgetTabType);
private:
    Ui::ControlTabWidget *ui;
    MapWidget mapTabWidget;
    void initValue();
};

#endif // CONTROLTABWIDGET_H
