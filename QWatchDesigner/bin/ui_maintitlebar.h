/********************************************************************************
** Form generated from reading UI file 'maintitlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTITLEBAR_H
#define UI_MAINTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTitleBar
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameBorder;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTitleName;
    QLabel *labelImage;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonMin;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *MainTitleBar)
    {
        if (MainTitleBar->objectName().isEmpty())
            MainTitleBar->setObjectName(QStringLiteral("MainTitleBar"));
        MainTitleBar->resize(688, 45);
        MainTitleBar->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MainTitleBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameBorder = new QFrame(MainTitleBar);
        frameBorder->setObjectName(QStringLiteral("frameBorder"));
        frameBorder->setFrameShape(QFrame::StyledPanel);
        frameBorder->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameBorder);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 9, 9, 9);
        labelTitleName = new QLabel(frameBorder);
        labelTitleName->setObjectName(QStringLiteral("labelTitleName"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        labelTitleName->setFont(font);
        labelTitleName->setScaledContents(true);

        horizontalLayout->addWidget(labelTitleName);

        labelImage = new QLabel(frameBorder);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setMinimumSize(QSize(25, 25));
        labelImage->setMaximumSize(QSize(25, 25));
        labelImage->setPixmap(QPixmap(QString::fromUtf8(":/res/res/image/image.png")));
        labelImage->setScaledContents(true);

        horizontalLayout->addWidget(labelImage);

        horizontalSpacer = new QSpacerItem(492, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonMin = new QPushButton(frameBorder);
        pushButtonMin->setObjectName(QStringLiteral("pushButtonMin"));
        pushButtonMin->setMinimumSize(QSize(25, 25));
        pushButtonMin->setMaximumSize(QSize(25, 25));
        QFont font1;
        font1.setPointSize(6);
        pushButtonMin->setFont(font1);
        pushButtonMin->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButtonMin);

        pushButtonClose = new QPushButton(frameBorder);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setMinimumSize(QSize(25, 25));
        pushButtonClose->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButtonClose);


        verticalLayout->addWidget(frameBorder);


        retranslateUi(MainTitleBar);

        QMetaObject::connectSlotsByName(MainTitleBar);
    } // setupUi

    void retranslateUi(QWidget *MainTitleBar)
    {
        MainTitleBar->setWindowTitle(QApplication::translate("MainTitleBar", "Form", 0));
        labelTitleName->setText(QApplication::translate("MainTitleBar", "Watch Designer", 0));
        labelImage->setText(QString());
        pushButtonMin->setText(QString());
        pushButtonClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainTitleBar: public Ui_MainTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTITLEBAR_H
