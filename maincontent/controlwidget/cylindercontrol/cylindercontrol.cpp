/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：柱状图
 * ***************************************/
#include "cylindercontrol.h"
#include "ui_cylindercontrol.h"

// 构造函数
CylinderControl::CylinderControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CylinderControl)
{
    ui->setupUi(this);
}

// 析构函数
CylinderControl::~CylinderControl()
{
    delete ui;
}

// 设置进度条值
void CylinderControl::setSliderValue(float value)
{
    sliderValue = value;
}

// 设置进度条文本
void CylinderControl::setSliderText(const QString &value)
{
    sliderText = value;
}

// 绘制事件
void CylinderControl::paintEvent(QPaintEvent *paintEvent)
{
    Q_UNUSED(paintEvent);
    QPainter painter(this);

    // 进度条最大高度
    float sliderMaxValue = this->height() * 0.9;

    //进度条高度
    float sliderHigh  = -this->height() * 0.8;

    //进度条宽度
    const int sliderWidth = 60;

    // 将坐标系的该点变成原点坐标
    painter.translate(this->width() * 0.3, sliderMaxValue);

    // 设置画笔为红色
    QPen pen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    // 画上面直线
    painter.drawLine(0, sliderHigh, sliderWidth, sliderHigh);

    // 画下面直线
    painter.drawLine(0, 0, sliderWidth, 0);

    // 画左边直线
    painter.drawLine(0, 0, 0, sliderHigh);

    // 画右边直线
    painter.drawLine(sliderWidth, 0, sliderWidth, sliderHigh);

    // 画上面直线线
    painter.drawLine(0, sliderHigh, sliderWidth, sliderHigh);

    // 画进度值
    painter.drawText(sliderWidth - 40, sliderHigh - 10, QString("%1%").arg(sliderValue));
    painter.drawText(5, 30, sliderText);


    //将矩形填充为白色
    QPolygon polyGon;
    polyGon<<QPoint(sliderWidth, 0);
    polyGon<<QPoint(sliderWidth, sliderHigh);
    polyGon<<QPoint(0, sliderHigh);
    polyGon<<QPoint(0, 0);
    painter.setBrush(Qt::white);
    painter.drawConvexPolygon(polyGon);

    //设置渐变
    QLinearGradient linerGradient = QLinearGradient(0, 0, 0, sliderHigh);
    linerGradient.setColorAt(0.0, Qt::cyan);
    linerGradient.setColorAt(0.3, Qt::green);
    linerGradient.setColorAt(0.7, Qt::yellow);
    linerGradient.setColorAt(1.0, Qt::red);

    QBrush brush(linerGradient);
    painter.setBrush(brush);

    painter.drawRect(QRectF(0, 0, sliderWidth, sliderHigh * sliderValue / 100));
    painter.end();
}

