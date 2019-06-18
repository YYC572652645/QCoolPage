/********************************************************************************
** Form generated from reading UI file 'qwatchdesigner.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWATCHDESIGNER_H
#define UI_QWATCHDESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <testdemowidget\testdemowidget.h>
#include <titlebar/maintitlebar.h>

QT_BEGIN_NAMESPACE

class Ui_QWatchDesigner
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    MainTitleBar *widgetTitle;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *widgetElement;
    QWidget *widgetTreeList;
    TestDemoWidget *widget_4;
    QWidget *widgetProperty;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QWatchDesigner)
    {
        if (QWatchDesigner->objectName().isEmpty())
            QWatchDesigner->setObjectName(QStringLiteral("QWatchDesigner"));
        QWatchDesigner->resize(800, 500);
        QWatchDesigner->setMinimumSize(QSize(800, 500));
        QWatchDesigner->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(QWatchDesigner);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new MainTitleBar(centralWidget);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        widgetTitle->setMinimumSize(QSize(0, 50));
        widgetTitle->setMaximumSize(QSize(16777215, 50));
        widgetTitle->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(widgetTitle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetElement = new QWidget(centralWidget);
        widgetElement->setObjectName(QStringLiteral("widgetElement"));

        verticalLayout->addWidget(widgetElement);

        widgetTreeList = new QWidget(centralWidget);
        widgetTreeList->setObjectName(QStringLiteral("widgetTreeList"));

        verticalLayout->addWidget(widgetTreeList);


        horizontalLayout->addLayout(verticalLayout);

        widget_4 = new TestDemoWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        horizontalLayout->addWidget(widget_4);

        widgetProperty = new QWidget(centralWidget);
        widgetProperty->setObjectName(QStringLiteral("widgetProperty"));

        horizontalLayout->addWidget(widgetProperty);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        QWatchDesigner->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QWatchDesigner);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QWatchDesigner->setStatusBar(statusBar);

        retranslateUi(QWatchDesigner);

        QMetaObject::connectSlotsByName(QWatchDesigner);
    } // setupUi

    void retranslateUi(QMainWindow *QWatchDesigner)
    {
        QWatchDesigner->setWindowTitle(QApplication::translate("QWatchDesigner", "QWatchDesigner", 0));
    } // retranslateUi

};

namespace Ui {
    class QWatchDesigner: public Ui_QWatchDesigner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWATCHDESIGNER_H
