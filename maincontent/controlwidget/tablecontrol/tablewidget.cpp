/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：表格窗口
 * ***************************************/
#include "tablewidget.h"
#include "ui_tablewidget.h"

// 构造函数
TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
TableWidget::~TableWidget()
{
    delete ui;
}

// 初始化数据
void TableWidget::initValue()
{
    QList<MapTableData> mapListTableData;
    for (int i = 0; i < 20; i++)
    {
        MapTableData mapTableData;
        for (int j = 0; j < TableControl::TYPE_MAX; j++)
        {
            CellData cellData;
            if (i < 3)
            {
                cellData.setDataType(CellData::DANGER);
            }
            else if (i < 6)
            {
                cellData.setDataType(CellData::WARNING);
            }

            if (j == TableControl::ID)
            {
                cellData.data = "520";
            }
            else if (j == TableControl::NAME)
            {
                cellData.data = "YYC";
            }
            else if (j == TableControl::TARGET)
            {
                cellData.data = "TEST";
            }
            else if (j == TableControl::POSITION)
            {
                cellData.data = "100";
            }
            mapTableData[j] = cellData;
        }
        mapListTableData.append(mapTableData);
    }
    ui->widgetTable->updateTableData(mapListTableData);
}
