#include "controltreewidget.h"
#include "ui_controltreewidget.h"

ControlTreeWidget::ControlTreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlTreeWidget)
{
    ui->setupUi(this);
    this->initValue();
}

ControlTreeWidget::~ControlTreeWidget()
{
    delete ui;
}

void ControlTreeWidget::initValue()
{
    ui->treeWidgetMenu->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->treeWidgetMenu->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->treeWidgetMenu->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeWidgetMenu->setHeaderHidden(true);
    ui->treeWidgetMenu->header()->setStretchLastSection(true);
    int lastIndex = ui->treeWidgetMenu->topLevelItemCount() - 1;
    ui->treeWidgetMenu->topLevelItem(lastIndex)->setSelected(true);

}

void ControlTreeWidget::on_treeWidgetMenu_clicked(const QModelIndex &index)
{
    emit sendShowIndex(WidgetTabType(index.row()));
}

void ControlTreeWidget::receiveShowCurrentTab(WidgetTabType widgetTabType)
{
    if (widgetTabType < ui->treeWidgetMenu->topLevelItemCount())
    {
        QTreeWidgetItem *treeWidgetItem = ui->treeWidgetMenu->topLevelItem(widgetTabType);
        ui->treeWidgetMenu->clearSelection();
        treeWidgetItem->setSelected(true);
    }
}
