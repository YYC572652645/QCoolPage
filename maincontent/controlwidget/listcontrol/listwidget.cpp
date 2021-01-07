/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：列表窗口，放置列表控件
 * ***************************************/
#include "listwidget.h"
#include "ui_listwidget.h"
#include "listcontrol.h"

// 构造函数
ListWidget::ListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
ListWidget::~ListWidget()
{
    delete ui;
}

// 初始化数据
void ListWidget::initValue()
{
    m_vboxLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    m_vboxLayout->setSpacing(0);
    const int LIST_NUMBER = 30;
    const int MAX_SCORE = 5;
    for (int i = 0; i < LIST_NUMBER; i++)
    {
        ListControl *listControl = new ListControl(this);
        listControl->makeStar(qrand() % MAX_SCORE + 1.5);
        m_vboxLayout->addWidget(listControl);
    }
}
