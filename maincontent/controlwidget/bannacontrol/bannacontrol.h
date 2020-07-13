/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：轮播图，使用双向循环链表思想，并使用Qt
 * 的动画组，然后对五张图片进行移动,如下所示
 * 1，2，3，4，5分别对应五个Label中的五个图片
 * 1的Label的坐标和大小，被2和5指向，即若向右移动
 * 则1的大小和位置变为2的大小和位置，2的位置变为3的
 * 大小和位置，依次类推
 * 若向左移动，则1的大小和位置则变为5的大小和位置，
 * 5的大小和位置则变为4的大小和位置，依次类推
 * 1 -> 2 -> 3 -> 4 -> 5 -> 1
 * 1 <- 2 <- 3 <- 4 <- 5 <- 1
 * 若不理解，课查看数据结构双向循环链表
 * ***************************************/
#ifndef BANNACONTROL_H
#define BANNACONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QButtonGroup>
#include <QLabel>
#include <QTimer>

namespace Ui {
class BannaControl;
}

namespace BannaSpace
{
const int INTERVAL_TIMER = 3000;
const int ANIMATION_DURTION = 200;
const QByteArray ANIMATION_GEOMETRY = "geometry";
const QString STYLE_SHEET = "border-image:url(%1)";
const QString FIRST_IMAGE_PATH = ":/res/res/image/banna/1.jpg";
const QString SECOND_IMAGE_PATH = ":/res/res/image/banna/2.jpg";
const QString THIRD_IMAGE_PATH = ":/res/res/image/banna/3.jpg";
const QString FOURTH_IMAGE_PATH = ":/res/res/image/banna/4.jpg";
const QString FIFTH_IMAGE_PATH = ":/res/res/image/banna/5.jpg";

enum SortWidget
{
    SORT_FIRST,
    SORT_SECOND,
    SORT_THIRD,
    SORT_FOURTH,
    SORT_FIFTH,
};

}

// 使用双向链表思想
typedef struct BannaData
{
    QPushButton *pushButton;
    QLabel *currentImageLabel;
    QLabel *nextImageLabel;
    QLabel *preImageLabel;
    QPropertyAnimation *proAnimation;
} BannaData;

class BannaControl : public QWidget
{
    Q_OBJECT

public:
    explicit BannaControl(QWidget *parent = 0);
    ~BannaControl();
private slots:
    void slot_changeImageTimer();
    void on_pushButtonLeft_clicked();
    void on_pushButtonRight_clicked();

private:
    Ui::BannaControl *ui;
    QTimer *changeImageTimer = nullptr;
    QList<BannaData> bannaDataList;
    QButtonGroup buttonGroup;
    QParallelAnimationGroup animationGroup;

    void initValue();
    void setNextAnimation();
    void setPreAnimation();
    int getMaxGeometryIndex(const QList<BannaData> &listData);
    void sortGeometry(const bool &isNextFlage);
    void addAnimationPixmap(QList<QString> &listPixmap);
};

#endif // BANNAWIDGET_H
