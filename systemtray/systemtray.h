#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include<QSystemTrayIcon>
#include<QAction>
#include<QApplication>
#include<QMenu>
#include<QWidget>
#include<QObject>

class SystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit SystemTray(QWidget * parent = 0);
    ~SystemTray();

    void addAction();
    void createAction();

public:
    QAction *getShowWidget() const;
    QAction *getMinWidget() const;
    QAction *getAboutSoftWare() const;

signals:
    void showMainWindow();
    void showAboutUs();

private:
    QMenu *myMenu;
    QAction* showWidget;
    QAction* minWidget;
    QAction* aboutSoftWare;
    QAction* exitSoftWare;
};

#endif // SYSTEMTRAY_H
