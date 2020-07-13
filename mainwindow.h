/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：最外层主窗体，绑定点击显示响应的页面之间
 * 的信号与槽，以及创建系统托盘
 * ***************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "systemtray/systemtray.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    void initValue();

private:
    SystemTray *syetemTray;
};

#endif // MAINWINDOW_H
