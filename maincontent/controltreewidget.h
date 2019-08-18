#ifndef CONTROLTREEWIDGET_H
#define CONTROLTREEWIDGET_H

#include <QWidget>
#include "globaldef.hpp"

namespace Ui {
class ControlTreeWidget;
}

class ControlTreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlTreeWidget(QWidget *parent = 0);
    ~ControlTreeWidget();
signals:
    void sendShowIndex(WidgetTabType);
private slots:
    void on_treeWidgetMenu_clicked(const QModelIndex &index);
    void receiveShowCurrentTab(WidgetTabType widgetTabType);

private:
    Ui::ControlTreeWidget *ui;
    void initValue();
};

#endif // CONTROLTREEWIDGET_H
