#include "testdemowidget.h"
#include "ui_testdemowidget.h"
#include <QFileDialog>
#include <QDebug>

TestDemoWidget::TestDemoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestDemoWidget)
{
    ui->setupUi(this);
    this->initValue();
}

TestDemoWidget::~TestDemoWidget()
{
    delete ui;
}

void TestDemoWidget::initValue()
{
    RootData rootData;
    rootData.rootString = "WatchDesigner";
    xmlDataModel.addRootNode(rootData);
}

void TestDemoWidget::on_pushButtonSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "保存", "test.xml", "xml(*.xml)");
    bool saveFlage = xmlDataModel.saveXmlData(fileName);

    if(saveFlage)
    {
        QString strText = ui->textEdit->toPlainText();
        ui->textEdit->setPlainText(strText + "保存成功");
    }
}

void TestDemoWidget::on_pushButtonAdd_clicked()
{
    ElementData elementData;
    elementData.userName = ui->lineEditName->text();
    elementData.userNumber = ui->lineEditnumber->text();
    elementData.userSex = ui->lineEditSex->text();
    elementData.userGroup = ui->lineEditDocument->text();
    xmlDataModel.appendElement(elementData);
    QString strText = ui->textEdit->toPlainText();
    strText.append("\n");
    strText.append("userName:" + elementData.userName + "\n");
    strText.append("userNumber:" + elementData.userNumber + "\n");
    strText.append("userSex:" + elementData.userSex + "\n");
    strText.append("userGroup:" + elementData.userGroup + "\n");
    ui->textEdit->setPlainText(strText);
}


