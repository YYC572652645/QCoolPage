/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板
 * ***************************************/
#ifndef FRAMECONTROL_H
#define FRAMECONTROL_H

#include <QFrame>

class QLabel;
class QPushButton;
class QLabel;

class FrameControl : public QFrame
{
    Q_OBJECT

public:
    explicit FrameControl(QFrame *parent = 0);
    ~FrameControl();
    void setLabelPixMap(const QPixmap &pixMap);
    void setTitleInfo(const QString &title);
    void createFrame(const QPixmap &pixMap, const QString &title);

private:
    QLabel *labelImage;
    QLabel *labelTitle;
    QPushButton *pushButtonDownLoad;
private:
    const int IMAGE_SIZE = 36;
    const int FIXED_WIDTH = 147;
    const int FIXED_HEIGHT = 80;
    const int BUTTON_WIDTH = 80;
    const int BUTTON_HEIGHT = 25;
};

#endif // FRAMECONTROL_H
