/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：列表控件，应用的信息和打星
 * ***************************************/
#include "listcontrol.h"
#include "ui_listcontrol.h"
#include <QHBoxLayout>
#include <QPixmap>

// 构造函数
ListControl::ListControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListControl)
{
    ui->setupUi(this);
}

// 析构函数
ListControl::~ListControl()
{
    delete ui;
}

// 评分
void ListControl::makeStar(float score)
{
    if (score > MAX_SCORE)
    {
        score = MAX_SCORE;
    }

    QHBoxLayout *hboxLayout = new QHBoxLayout(ui->widgetStar);
    hboxLayout->addStretch();
    int starCount = static_cast<int>(score);
    for (int i = 0; i < starCount; i++)
    {
        hboxLayout->addWidget(createStarLabel(QPixmap(STAR_PATH)));
    }
    if (score - starCount)
    {
        hboxLayout->addWidget(createStarLabel(QPixmap(HALF_STAR_PATH)));
    }
    hboxLayout->addStretch();
}

// 创建星控件
QLabel *ListControl::createStarLabel(const QPixmap &pix)
{
    QLabel *label = new QLabel(ui->widgetStar);
    label->setFixedSize(LABEL_SIZE);
    label->setPixmap(pix);
    label->setScaledContents(true);
    return label;
}
