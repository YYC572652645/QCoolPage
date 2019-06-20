#ifndef MAINTITLEBAR_H
#define MAINTITLEBAR_H

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class MainTitleBar;
}

class MainTitleBar : public TitleBar
{
    Q_OBJECT

public:
    explicit MainTitleBar(QWidget *parent = 0);
    ~MainTitleBar();

private slots:
    void on_pushButtonClose_clicked();
    void on_pushButtonMin_clicked();
    void on_pushButtonMax_clicked();
    void on_pushButtonNormal_clicked();

private:
    Ui::MainTitleBar *ui;
    void showNormalMax();
};

#endif // MAINTITLEBAR_H
