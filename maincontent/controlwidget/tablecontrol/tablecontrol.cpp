#include "tablecontrol.h"
#include "ui_tablecontrol.h"

TableControl::TableControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableControl)
{
    ui->setupUi(this);
    this->initValue();
}

TableControl::~TableControl()
{
    delete ui;
}

void TableControl::initValue()
{
    ui->tableWidgetData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetData->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidgetData->setAlternatingRowColors(true);
    ui->tableWidgetData->verticalHeader()->setHidden(true);
    ui->tableWidgetData->setShowGrid(false);
    ui->tableWidgetData->viewport()->setFocusPolicy(Qt::NoFocus);
}

// 添加数据
void TableControl::appendTableData(const MapTableData &mapTableData)
{
    m_mapListTableData.append(mapTableData);
    ui->tableWidgetData->setRowCount(m_mapListTableData.size());

    for (auto iter = mapTableData.begin(); iter != mapTableData.end(); iter++)
    {
        QTableWidgetItem *tableWidgetItem = new QTableWidgetItem(iter.value().data);
        tableWidgetItem->setTextColor(iter.value().color);
        tableWidgetItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetData->setItem(m_mapListTableData.size() - 1, iter.key(), tableWidgetItem);
    }
}

void TableControl::updateTableData(const QList<MapTableData> &mapListData)
{
    for (MapTableData mapTableData : mapListData)
    {
        this->appendTableData(mapTableData);
    }
}

