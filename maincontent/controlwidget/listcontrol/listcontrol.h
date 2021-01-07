/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：列表控件，应用的信息和打星
 * ***************************************/
#ifndef LISTCONTROL_H
#define LISTCONTROL_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class ListControl;
}

class ListControl : public QWidget
{
    Q_OBJECT

public:
    explicit ListControl(QWidget *parent = 0);
    ~ListControl();
    void makeStar(float score);

private:
    QLabel *createStarLabel(const QPixmap &pix);
private:
    Ui::ListControl *ui;
    QList<QLabel*> m_listStarLabel;
private:
    const int MAX_SCORE = 5;
    const QSize LABEL_SIZE = QSize(16, 16);
    const QString STAR_PATH = ":/res/res/image/other/star.png";
    const QString HALF_STAR_PATH = ":/res/res/image/other/half_star.png";
};

#endif // LISTCONTROL_H
