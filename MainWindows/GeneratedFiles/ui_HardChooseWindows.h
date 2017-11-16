/********************************************************************************
** Form generated from reading UI file 'HardChooseWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARDCHOOSEWINDOWS_H
#define UI_HARDCHOOSEWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HardChooseWindows
{
public:
    QLabel *label_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelEasyLevel;
    QRadioButton *radioButtonEasyLevel;
    QLabel *labelMiddleLevel;
    QRadioButton *radioButtonMiddleLevel;
    QLabel *labelHighLevel;
    QRadioButton *radioButtonHighLevel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonLevelOk;
    QPushButton *buttonLevelReturn;

    void setupUi(QWidget *HardChooseWindows)
    {
        if (HardChooseWindows->objectName().isEmpty())
            HardChooseWindows->setObjectName(QStringLiteral("HardChooseWindows"));
        HardChooseWindows->resize(400, 300);
        label_4 = new QLabel(HardChooseWindows);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 10, 121, 21));
        label_4->setWordWrap(false);
        widget = new QWidget(HardChooseWindows);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 50, 321, 181));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelEasyLevel = new QLabel(widget);
        labelEasyLevel->setObjectName(QStringLiteral("labelEasyLevel"));
        labelEasyLevel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelEasyLevel, 0, 0, 1, 1);

        radioButtonEasyLevel = new QRadioButton(widget);
        radioButtonEasyLevel->setObjectName(QStringLiteral("radioButtonEasyLevel"));

        gridLayout->addWidget(radioButtonEasyLevel, 0, 1, 1, 1);

        labelMiddleLevel = new QLabel(widget);
        labelMiddleLevel->setObjectName(QStringLiteral("labelMiddleLevel"));
        labelMiddleLevel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelMiddleLevel, 1, 0, 1, 1);

        radioButtonMiddleLevel = new QRadioButton(widget);
        radioButtonMiddleLevel->setObjectName(QStringLiteral("radioButtonMiddleLevel"));

        gridLayout->addWidget(radioButtonMiddleLevel, 1, 1, 1, 1);

        labelHighLevel = new QLabel(widget);
        labelHighLevel->setObjectName(QStringLiteral("labelHighLevel"));
        labelHighLevel->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelHighLevel, 2, 0, 1, 1);

        radioButtonHighLevel = new QRadioButton(widget);
        radioButtonHighLevel->setObjectName(QStringLiteral("radioButtonHighLevel"));

        gridLayout->addWidget(radioButtonHighLevel, 2, 1, 1, 1);

        widget1 = new QWidget(HardChooseWindows);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(50, 240, 301, 51));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonLevelOk = new QPushButton(widget1);
        buttonLevelOk->setObjectName(QStringLiteral("buttonLevelOk"));

        horizontalLayout->addWidget(buttonLevelOk);

        buttonLevelReturn = new QPushButton(widget1);
        buttonLevelReturn->setObjectName(QStringLiteral("buttonLevelReturn"));

        horizontalLayout->addWidget(buttonLevelReturn);


        retranslateUi(HardChooseWindows);

        QMetaObject::connectSlotsByName(HardChooseWindows);
    } // setupUi

    void retranslateUi(QWidget *HardChooseWindows)
    {
        HardChooseWindows->setWindowTitle(QApplication::translate("HardChooseWindows", "HardChooseWindows", Q_NULLPTR));
        label_4->setText(QApplication::translate("HardChooseWindows", "\350\257\267\351\200\211\346\213\251\345\256\236\351\252\214\351\232\276\345\272\246", Q_NULLPTR));
        labelEasyLevel->setText(QApplication::translate("HardChooseWindows", "\345\210\235\347\272\247", Q_NULLPTR));
        radioButtonEasyLevel->setText(QApplication::translate("HardChooseWindows", "RadioButton1", Q_NULLPTR));
        labelMiddleLevel->setText(QApplication::translate("HardChooseWindows", "\344\270\255\347\272\247", Q_NULLPTR));
        radioButtonMiddleLevel->setText(QApplication::translate("HardChooseWindows", "RadioButton2", Q_NULLPTR));
        labelHighLevel->setText(QApplication::translate("HardChooseWindows", "\351\253\230\347\272\247", Q_NULLPTR));
        radioButtonHighLevel->setText(QApplication::translate("HardChooseWindows", "RadioButton3", Q_NULLPTR));
        buttonLevelOk->setText(QApplication::translate("HardChooseWindows", "\347\241\256\345\256\232", Q_NULLPTR));
        buttonLevelReturn->setText(QApplication::translate("HardChooseWindows", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HardChooseWindows: public Ui_HardChooseWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARDCHOOSEWINDOWS_H
