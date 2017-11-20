/********************************************************************************
** Form generated from reading UI file 'LevelEasy.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELEASY_H
#define UI_LEVELEASY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelEasy
{
public:
    QPushButton *buttonRevert;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *buttonJZFilter;
    QPushButton *buttonFKFilter;
    QPushButton *buttonGSFilter;
    QLabel *label;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *buttonDilate;
    QPushButton *buttonErode;
    QPushButton *buttonOpenOperation;
    QPushButton *buttonCloseOperation;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QPushButton *buttonThreshold;
    QPushButton *buttonAdaptiveThreshold;
    QWidget *widget3;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QPushButton *buttonCanny;
    QPushButton *buttonSobel;
    QPushButton *buttonLaplace;

    void setupUi(QWidget *LevelEasy)
    {
        if (LevelEasy->objectName().isEmpty())
            LevelEasy->setObjectName(QStringLiteral("LevelEasy"));
        LevelEasy->resize(270, 700);
        buttonRevert = new QPushButton(LevelEasy);
        buttonRevert->setObjectName(QStringLiteral("buttonRevert"));
        buttonRevert->setGeometry(QRect(10, 10, 93, 28));
        widget = new QWidget(LevelEasy);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 60, 251, 111));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonJZFilter = new QPushButton(widget);
        buttonJZFilter->setObjectName(QStringLiteral("buttonJZFilter"));
        buttonJZFilter->setAutoFillBackground(false);

        gridLayout->addWidget(buttonJZFilter, 1, 1, 1, 1);

        buttonFKFilter = new QPushButton(widget);
        buttonFKFilter->setObjectName(QStringLiteral("buttonFKFilter"));
        buttonFKFilter->setAutoFillBackground(false);

        gridLayout->addWidget(buttonFKFilter, 1, 0, 1, 1);

        buttonGSFilter = new QPushButton(widget);
        buttonGSFilter->setObjectName(QStringLiteral("buttonGSFilter"));
        buttonGSFilter->setAutoFillBackground(false);

        gridLayout->addWidget(buttonGSFilter, 2, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        widget1 = new QWidget(LevelEasy);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 200, 251, 111));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        buttonDilate = new QPushButton(widget1);
        buttonDilate->setObjectName(QStringLiteral("buttonDilate"));

        gridLayout_2->addWidget(buttonDilate, 1, 0, 1, 1);

        buttonErode = new QPushButton(widget1);
        buttonErode->setObjectName(QStringLiteral("buttonErode"));

        gridLayout_2->addWidget(buttonErode, 1, 1, 1, 1);

        buttonOpenOperation = new QPushButton(widget1);
        buttonOpenOperation->setObjectName(QStringLiteral("buttonOpenOperation"));

        gridLayout_2->addWidget(buttonOpenOperation, 2, 0, 1, 1);

        buttonCloseOperation = new QPushButton(widget1);
        buttonCloseOperation->setObjectName(QStringLiteral("buttonCloseOperation"));

        gridLayout_2->addWidget(buttonCloseOperation, 2, 1, 1, 1);

        widget2 = new QWidget(LevelEasy);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 340, 251, 81));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        buttonThreshold = new QPushButton(widget2);
        buttonThreshold->setObjectName(QStringLiteral("buttonThreshold"));

        gridLayout_3->addWidget(buttonThreshold, 1, 0, 1, 1);

        buttonAdaptiveThreshold = new QPushButton(widget2);
        buttonAdaptiveThreshold->setObjectName(QStringLiteral("buttonAdaptiveThreshold"));

        gridLayout_3->addWidget(buttonAdaptiveThreshold, 1, 1, 1, 1);

        widget3 = new QWidget(LevelEasy);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(10, 450, 251, 111));
        gridLayout_4 = new QGridLayout(widget3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        buttonCanny = new QPushButton(widget3);
        buttonCanny->setObjectName(QStringLiteral("buttonCanny"));

        gridLayout_4->addWidget(buttonCanny, 1, 0, 1, 1);

        buttonSobel = new QPushButton(widget3);
        buttonSobel->setObjectName(QStringLiteral("buttonSobel"));

        gridLayout_4->addWidget(buttonSobel, 1, 1, 1, 1);

        buttonLaplace = new QPushButton(widget3);
        buttonLaplace->setObjectName(QStringLiteral("buttonLaplace"));

        gridLayout_4->addWidget(buttonLaplace, 2, 0, 1, 1);


        retranslateUi(LevelEasy);

        QMetaObject::connectSlotsByName(LevelEasy);
    } // setupUi

    void retranslateUi(QWidget *LevelEasy)
    {
        LevelEasy->setWindowTitle(QApplication::translate("LevelEasy", "LevelEasy", Q_NULLPTR));
        buttonRevert->setText(QApplication::translate("LevelEasy", "\346\201\242\345\244\215\344\270\272\345\216\237\345\233\276", Q_NULLPTR));
        buttonJZFilter->setText(QApplication::translate("LevelEasy", "\345\235\207\345\200\274\346\273\244\346\263\242", Q_NULLPTR));
        buttonFKFilter->setText(QApplication::translate("LevelEasy", "\346\226\271\346\241\206\346\273\244\346\263\242", Q_NULLPTR));
        buttonGSFilter->setText(QApplication::translate("LevelEasy", "\351\253\230\346\226\257\346\273\244\346\263\242", Q_NULLPTR));
        label->setText(QApplication::translate("LevelEasy", "\346\273\244\346\263\242\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("LevelEasy", "\345\275\242\346\200\201\345\255\246\357\274\232", Q_NULLPTR));
        buttonDilate->setText(QApplication::translate("LevelEasy", "\350\206\250\350\203\200", Q_NULLPTR));
        buttonErode->setText(QApplication::translate("LevelEasy", "\350\205\220\350\232\200", Q_NULLPTR));
        buttonOpenOperation->setText(QApplication::translate("LevelEasy", "\345\274\200\350\277\220\347\256\227", Q_NULLPTR));
        buttonCloseOperation->setText(QApplication::translate("LevelEasy", "\351\227\255\350\277\220\347\256\227", Q_NULLPTR));
        label_3->setText(QApplication::translate("LevelEasy", "\344\272\214\345\200\274\345\214\226\357\274\232", Q_NULLPTR));
        buttonThreshold->setText(QApplication::translate("LevelEasy", "\345\233\272\345\256\232\344\272\214\345\200\274\345\214\226", Q_NULLPTR));
        buttonAdaptiveThreshold->setText(QApplication::translate("LevelEasy", "\350\207\252\351\200\202\345\272\224\344\272\214\345\200\274\345\214\226", Q_NULLPTR));
        label_4->setText(QApplication::translate("LevelEasy", "\350\276\271\347\274\230\346\243\200\346\265\213\357\274\232", Q_NULLPTR));
        buttonCanny->setText(QApplication::translate("LevelEasy", "Canny\347\256\227\345\255\220", Q_NULLPTR));
        buttonSobel->setText(QApplication::translate("LevelEasy", "Sobel\347\256\227\345\255\220", Q_NULLPTR));
        buttonLaplace->setText(QApplication::translate("LevelEasy", "Laplace\347\256\227\345\255\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LevelEasy: public Ui_LevelEasy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELEASY_H
