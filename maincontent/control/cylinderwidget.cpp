#include "cylinderwidget.h"
#include "ui_cylinderwidget.h"
#include <QLinearGradient>
#include <QPainter>

CylinderWidget::CylinderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CylinderWidget)
{
    ui->setupUi(this);
    ui->widgetFirst->installEventFilter(this);
    ui->widgetSecond->installEventFilter(this);
    ui->widgetThird->installEventFilter(this);
    ui->widgetFourth->installEventFilter(this);
    ui->widgetFifth->installEventFilter(this);
    ui->widgetSixth->installEventFilter(this);
}

CylinderWidget::~CylinderWidget()
{
    delete ui;
}

void CylinderWidget::paintImage(QWidget * widget, float sliderValue, QString text)
{
    if(NULL == widget) return;

    QPainter painter(widget);

    float sliderMaxValue = widget->height() * 0.9;
    float sliderHigh  = -widget->height() * 0.8;  //进度条高度
    const int sliderWidth = 60;                   //进度条宽度

    // 将坐标系的该点变成原点坐标
    painter.translate(widget->width() * 0.3, sliderMaxValue);

    // 设置画笔为红色
    QPen pen(Qt::white, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    // 画上面直线线
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
    painter.drawText(sliderWidth - 40, sliderHigh - 10,tr("%%1").arg(sliderValue * 100));
    painter.drawText(5, 30, text);


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

    painter.drawRect(0, 0, sliderWidth, sliderHigh * sliderValue);

    painter.end();
}

bool CylinderWidget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->widgetFirst && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetFirst, 0.15, "柱状图一");
    }
    else if(watched == ui->widgetSecond && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetSecond, 0.30, "柱状图二");
    }
    else if(watched == ui->widgetThird && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetThird, 0.45, "柱状图三");
    }
    else if(watched == ui->widgetFourth && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetFourth, 0.60, "柱状图四");
    }
    else if(watched == ui->widgetFifth && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetFifth, 0.80, "柱状图五");
    }
    else if(watched == ui->widgetSixth && event->type() == QEvent::Paint)
    {
        paintImage(ui->widgetSixth, 0.95, "柱状图六");
    }

    return QWidget::eventFilter(watched,event);
}
