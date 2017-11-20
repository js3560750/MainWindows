/********************************************************************************
** Form generated from reading UI file 'LevelMiddle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELMIDDLE_H
#define UI_LEVELMIDDLE_H

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

class Ui_LevelMiddle
{
public:
    QPushButton *buttonRevert;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *buttonJZFilter;
    QPushButton *buttonFKFilter;
    QPushButton *buttonGSFilter;
    QLabel *label;

    void setupUi(QWidget *LevelMiddle)
    {
        if (LevelMiddle->objectName().isEmpty())
            LevelMiddle->setObjectName(QStringLiteral("LevelMiddle"));
        LevelMiddle->resize(270, 700);
        buttonRevert = new QPushButton(LevelMiddle);
        buttonRevert->setObjectName(QStringLiteral("buttonRevert"));
        buttonRevert->setGeometry(QRect(10, 20, 93, 28));
        layoutWidget = new QWidget(LevelMiddle);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 60, 251, 111));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonJZFilter = new QPushButton(layoutWidget);
        buttonJZFilter->setObjectName(QStringLiteral("buttonJZFilter"));
        buttonJZFilter->setAutoFillBackground(false);

        gridLayout->addWidget(buttonJZFilter, 1, 1, 1, 1);

        buttonFKFilter = new QPushButton(layoutWidget);
        buttonFKFilter->setObjectName(QStringLiteral("buttonFKFilter"));
        buttonFKFilter->setAutoFillBackground(false);

        gridLayout->addWidget(buttonFKFilter, 1, 0, 1, 1);

        buttonGSFilter = new QPushButton(layoutWidget);
        buttonGSFilter->setObjectName(QStringLiteral("buttonGSFilter"));
        buttonGSFilter->setAutoFillBackground(false);

        gridLayout->addWidget(buttonGSFilter, 2, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(LevelMiddle);

        QMetaObject::connectSlotsByName(LevelMiddle);
    } // setupUi

    void retranslateUi(QWidget *LevelMiddle)
    {
        LevelMiddle->setWindowTitle(QApplication::translate("LevelMiddle", "LevelMiddle", Q_NULLPTR));
        buttonRevert->setText(QApplication::translate("LevelMiddle", "\346\201\242\345\244\215\344\270\272\345\216\237\345\233\276", Q_NULLPTR));
        buttonJZFilter->setText(QApplication::translate("LevelMiddle", "\345\235\207\345\200\274\346\273\244\346\263\242", Q_NULLPTR));
        buttonFKFilter->setText(QApplication::translate("LevelMiddle", "\346\226\271\346\241\206\346\273\244\346\263\242", Q_NULLPTR));
        buttonGSFilter->setText(QApplication::translate("LevelMiddle", "\351\253\230\346\226\257\346\273\244\346\263\242", Q_NULLPTR));
        label->setText(QApplication::translate("LevelMiddle", "\346\273\244\346\263\242\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LevelMiddle: public Ui_LevelMiddle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELMIDDLE_H
