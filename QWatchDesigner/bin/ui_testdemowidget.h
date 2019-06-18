/********************************************************************************
** Form generated from reading UI file 'testdemowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTDEMOWIDGET_H
#define UI_TESTDEMOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestDemoWidget
{
public:
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditnumber;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditSex;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditDocument;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonSave;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *TestDemoWidget)
    {
        if (TestDemoWidget->objectName().isEmpty())
            TestDemoWidget->setObjectName(QStringLiteral("TestDemoWidget"));
        TestDemoWidget->resize(526, 329);
        horizontalLayout_6 = new QHBoxLayout(TestDemoWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(TestDemoWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        lineEditnumber = new QLineEdit(groupBox);
        lineEditnumber->setObjectName(QStringLiteral("lineEditnumber"));
        lineEditnumber->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(lineEditnumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setScaledContents(true);

        horizontalLayout_2->addWidget(label_2);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setScaledContents(true);

        horizontalLayout_4->addWidget(label_4);

        lineEditSex = new QLineEdit(groupBox);
        lineEditSex->setObjectName(QStringLiteral("lineEditSex"));
        lineEditSex->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(lineEditSex);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setScaledContents(true);

        horizontalLayout_3->addWidget(label_3);

        lineEditDocument = new QLineEdit(groupBox);
        lineEditDocument->setObjectName(QStringLiteral("lineEditDocument"));
        lineEditDocument->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(lineEditDocument);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButtonAdd = new QPushButton(groupBox);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setMinimumSize(QSize(100, 30));
        pushButtonAdd->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(pushButtonAdd);

        pushButtonSave = new QPushButton(groupBox);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(100, 30));
        pushButtonSave->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(pushButtonSave);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addWidget(groupBox);

        textEdit = new QTextEdit(TestDemoWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_6->addWidget(textEdit);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        retranslateUi(TestDemoWidget);

        QMetaObject::connectSlotsByName(TestDemoWidget);
    } // setupUi

    void retranslateUi(QWidget *TestDemoWidget)
    {
        TestDemoWidget->setWindowTitle(QApplication::translate("TestDemoWidget", "Form", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("TestDemoWidget", "\345\267\245\345\217\267\357\274\232", 0));
        lineEditnumber->setText(QApplication::translate("TestDemoWidget", "n011936", 0));
        label_2->setText(QApplication::translate("TestDemoWidget", "\345\247\223\345\220\215\357\274\232", 0));
        lineEditName->setText(QApplication::translate("TestDemoWidget", "\346\256\267\345\256\207\350\276\260", 0));
        label_4->setText(QApplication::translate("TestDemoWidget", "\346\200\247\345\210\253\357\274\232", 0));
        lineEditSex->setText(QApplication::translate("TestDemoWidget", "\347\224\267", 0));
        label_3->setText(QApplication::translate("TestDemoWidget", "\351\203\250\351\227\250\357\274\232", 0));
        lineEditDocument->setText(QApplication::translate("TestDemoWidget", "PC\350\275\257\344\273\266\351\203\250", 0));
        pushButtonAdd->setText(QApplication::translate("TestDemoWidget", "\346\267\273\345\212\240", 0));
        pushButtonSave->setText(QApplication::translate("TestDemoWidget", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class TestDemoWidget: public Ui_TestDemoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTDEMOWIDGET_H
