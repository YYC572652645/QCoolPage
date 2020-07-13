/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：表格
 * ***************************************/
#ifndef TABLECONTROL_H
#define TABLECONTROL_H

#include <QWidget>
#include <QMap>

namespace Ui {
class TableControl;
}

typedef struct CellData
{
    enum DataType
    {
        DANGER,
        WARNING,
        NORMAL,
    };
    CellData() : color(Qt::white)
    {

    }
    void setDataType(DataType dataType)
    {
        if (dataType == DANGER)
        {
            color = QColor(240, 0, 0);
        }
        else if (dataType == WARNING)
        {
            color = QColor(238, 184, 76);
        }
        else {
            color = QColor(Qt::white);
        }
    }
    QString data;
    QColor color;
}CellData;

using MapTableData = QMap<int, CellData>;

class TableControl : public QWidget
{
    Q_OBJECT
public:
    enum TableDataType
    {
        ID,
        NAME,
        TARGET,
        POSITION,
        /////////
        TYPE_MAX,
    };
    explicit TableControl(QWidget *parent = nullptr);
    ~TableControl();
    void appendTableData(const MapTableData &mapTableData);
    void updateTableData(const QList<MapTableData> &mapListData);

private:
    Ui::TableControl *ui;
    QList<MapTableData> m_mapListTableData;
private:
    void initValue();
};

#endif // TABLECONTROL_H
