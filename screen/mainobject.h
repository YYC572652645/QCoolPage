/*****************************************
 * 作者: YYC
 * 日期: 2021-01-07
 * 功能：初始化类
 * ***************************************/
#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include <QObject>

class MainWindow;


class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();

public :
    void setInit();//初始化

private:
    MainWindow *m_mainWindow;

};

#endif // MAINOBJECT_H
