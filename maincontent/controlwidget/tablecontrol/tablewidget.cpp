#include "tablewidget.h"
#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);
    this->initValue();
}

TableWidget::~TableWidget()
{
    delete ui;
}

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
