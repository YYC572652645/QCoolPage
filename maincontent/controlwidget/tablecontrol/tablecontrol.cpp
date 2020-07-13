/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：表格
 * ***************************************/
#include "tablecontrol.h"
#include "ui_tablecontrol.h"

// 构造函数
TableControl::TableControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableControl)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
TableControl::~TableControl()
{
    delete ui;
}

// 初始化数据
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

// 更新数据
void TableControl::updateTableData(const QList<MapTableData> &mapListData)
{
    for (MapTableData mapTableData : mapListData)
    {
        this->appendTableData(mapTableData);
    }
}

