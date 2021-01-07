/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：列表窗口，放置列表控件
 * ***************************************/
#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class ListWidget;
}

class ListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ListWidget(QWidget *parent = 0);
    ~ListWidget();
private:
    void initValue();
private:
    Ui::ListWidget *ui;
    QVBoxLayout *m_vboxLayout = nullptr;
};

#endif // LISTWIDGET_H
