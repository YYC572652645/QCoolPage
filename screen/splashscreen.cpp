/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：创建闪屏
 * ***************************************/
#include "splashscreen.h"
#include <QPainter>
#include <QTimer>
#include <QApplication>
#include <QGuiApplication>
#include <QDebug>
#include "globaldef.hpp"

SplashScreen *SplashScreen::m_staticInstance = nullptr;

// 构造函数
SplashScreen::SplashScreen(const QPixmap &pixmap)
    : QSplashScreen(pixmap)
    , m_percent(0)
    , m_widget(nullptr)
{
}

// 析构函数
SplashScreen::~SplashScreen()
{

}

// 单例模式
SplashScreen *SplashScreen::getInstance()
{
    if(nullptr == m_staticInstance)
    {
        m_staticInstance = new SplashScreen(QPixmap(":/res/res/image/other/splash.png"));
    }
    return m_staticInstance;
}

// 绘制事件
void SplashScreen::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    const int OFFSET_VALUE = 70;
    const int SLIDER_HEIGHT = 10;
    const int BORDER_X_RADIUS = 8;
    const int BORDER_Y_RADIUS = 4;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font(QString("微软雅黑"));
    QPen painterPen;
    painterPen.setColor(Qt::white);
    painter.setPen(painterPen);
    QBrush brush(QColor(100, 100, 100 ,255));
    painter.setBrush(brush);
    painter.drawRoundedRect(OFFSET_VALUE, this->height() - OFFSET_VALUE
                            ,(this->width()- OFFSET_VALUE * 2)
                            ,BORDER_X_RADIUS,BORDER_Y_RADIUS,SLIDER_HEIGHT);

    // 绘制消息文本
    {
        font.setPixelSize(16);
        font.setBold(true);
        painter.setFont(font);
        painterPen.setColor(Qt::yellow);
        painter.setPen(painterPen);
        painter.drawText(0, this->height()- OFFSET_VALUE * 2, this->width(), OFFSET_VALUE, Qt::AlignCenter, m_message);
    }

    // 绘制进度条
    {
        painterPen.setColor(Qt::white);
        painter.setPen(painterPen);
        if(m_percent != 0)
        {
            QBrush brush(QColor(150, 230, 100 ,255));
            painter.setBrush(brush);
            painter.drawRoundedRect(OFFSET_VALUE, this->height() - OFFSET_VALUE
                                    , (this->rect().width()- OFFSET_VALUE * 2) * m_percent / 100
                                    , BORDER_X_RADIUS,BORDER_Y_RADIUS,SLIDER_HEIGHT);
        }
    }

    // 绘制进度文本
    {
        font.setPixelSize(14);
        font.setBold(false);
        painter.setFont(font);
        painterPen.setColor(Qt::white);
        painter.setPen(painterPen);
        QString drawText = QString::number(m_percent,'f',0) + QString("%");
        painter.drawText(0, this->height() - OFFSET_VALUE, this->width(), OFFSET_VALUE, Qt::AlignCenter, drawText);
        painter.end();
    }

    // 绘制圆角窗体
    {
        QPainterPath painterPathPath;
        QRectF rect = QRectF(0, 0, this->width(), this->height());
        painterPathPath.addRoundRect(rect, BORDER_X_RADIUS, BORDER_X_RADIUS);
        QPolygon polygon= painterPathPath.toFillPolygon().toPolygon();
        QRegion region(polygon);
        this->setMask(region);
    }
}

// 设置进度
void SplashScreen::setStagePercent(const int &percent, const QString &message)
{
    if(this->isHidden())
    {
        this->show();
    }
    if(!this->isActiveWindow())
    {
        this->activateWindow();
        this->raise();
    }
    m_message = message;

    while (m_percent < percent)
    {
        m_percent = m_percent + 0.02;
        qApp->processEvents();
        this->repaint();
    }
}

// 开始
void SplashScreen::setStart(QWidget *widget, const QString &title, const QString &logoFile)
{
    if (nullptr != widget)
    {
        m_widget = widget;
        m_pixLogo = QPixmap(logoFile);
        m_textLogo = title;
    }
}

// 结束
void SplashScreen::setFinish()
{
    this->close();
    if (nullptr != m_widget)
    {
        m_widget->activateWindow();
        m_widget->raise();
    }
}
