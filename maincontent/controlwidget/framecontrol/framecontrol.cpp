/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板
 * ***************************************/
#include "framecontrol.h"
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

// 构造函数
FrameControl::FrameControl(QFrame *parent) :
    QFrame(parent)
{
    this->setFixedWidth(FIXED_WIDTH);
    this->setFixedHeight(FIXED_HEIGHT);
    this->setObjectName("frameApplication");
}

// 析构函数
FrameControl::~FrameControl()
{
}

// 设置面板图标
void FrameControl::setLabelPixMap(const QPixmap &pixMap)
{
    if (labelImage != nullptr) {
        labelImage->setPixmap(pixMap);
    }
}

// 设置标题
void FrameControl::setTitleInfo(const QString &title)
{
    if (labelTitle != nullptr) {
        labelTitle->setText(title);
    }
}

// 创建面板
void FrameControl::createFrame(const QPixmap &pixMap, const QString &title)
{
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    labelImage = new QLabel(this);
    labelImage->setFixedSize(IMAGE_SIZE, IMAGE_SIZE);
    labelImage->setPixmap(pixMap);
    labelImage->setScaledContents(true);


    labelTitle = new QLabel(this);
    labelTitle->setText(title);
    labelTitle->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    pushButtonDownLoad = new QPushButton(this);
    pushButtonDownLoad->setText(tr("下载"));
    pushButtonDownLoad->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(labelTitle);
    vBoxLayout->addWidget(pushButtonDownLoad);
    hBoxLayout->addWidget(labelImage);
    hBoxLayout->addLayout(vBoxLayout);
}
