#ifndef BANNAWIDGET_H
#define BANNAWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QButtonGroup>
#include <QLabel>
#include <QTimer>

namespace Ui {
class BannaWidget;
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
}BannaData;

class BannaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BannaWidget(QWidget *parent = 0);
    ~BannaWidget();
private slots:
    void slot_changeImageTimer();
    void on_pushButtonLeft_clicked();
    void on_pushButtonRight_clicked();

private:
    Ui::BannaWidget *ui;
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
