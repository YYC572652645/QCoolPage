/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：创建闪屏
 * ***************************************/

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <QSplashScreen>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(const QPixmap &pixmap);
    ~SplashScreen();
    static SplashScreen *getInstance();

protected:
    void paintEvent (QPaintEvent *event);

public:
    void setStagePercent(const int &percent,const QString &message);
    void setStart(QWidget *widget, const QString &title,const QString &logoFile);
    void setFinish();

private:
    static SplashScreen *m_staticInstance;
    double m_percent;
    QWidget *m_widget;
    QPixmap m_pixLogo;
    QString m_textLogo;
    QString m_message;

};

#endif // SPLASHSCREEN_H
