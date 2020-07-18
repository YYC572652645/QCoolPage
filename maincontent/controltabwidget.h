#ifndef CONTROLTABWIDGET_H
#define CONTROLTABWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "globaldef.hpp"
#include "controlwidget/bannacontrol/bannacontrol.h"

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

signals:
    void sendShowIndex(WidgetTabType);

private slots:
    void receiveShowCurrentTab(WidgetTabType widgetTabType);

private:
    Ui::ControlTabWidget *ui;
    MapWidget mapTabWidget;
    void initValue();
};

#endif // CONTROLTABWIDGET_H
