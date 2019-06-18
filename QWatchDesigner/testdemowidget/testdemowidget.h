#ifndef TESTDEMOWIDGET_H
#define TESTDEMOWIDGET_H

#include <QWidget>
#include "xmlhandler/xmldatamodel.h"

namespace Ui {
class TestDemoWidget;
}

class TestDemoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestDemoWidget(QWidget *parent = 0);
    ~TestDemoWidget();

private slots:
    void on_pushButtonSave_clicked();
    void on_pushButtonAdd_clicked();

private:
    Ui::TestDemoWidget *ui;
    XmlDataModel xmlDataModel;

    void initValue();
};

#endif // TESTDEMOWIDGET_H
