/********************************************************************************
** Form generated from reading UI file 'SceneWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEWINDOWS_H
#define UI_SCENEWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneWindows
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *SceneWindows)
    {
        if (SceneWindows->objectName().isEmpty())
            SceneWindows->setObjectName(QStringLiteral("SceneWindows"));
        SceneWindows->setEnabled(true);
        SceneWindows->resize(715, 489);
        layoutWidget = new QWidget(SceneWindows);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 691, 471));
        layoutWidget->setMinimumSize(QSize(691, 471));
        layoutWidget->setMaximumSize(QSize(691, 471));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(223, 432));
        label->setMaximumSize(QSize(223, 432));
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::Box);
        label->setLineWidth(2);

        verticalLayout->addWidget(label);

        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(223, 28));
        pushButton_1->setMaximumSize(QSize(223, 28));

        verticalLayout->addWidget(pushButton_1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(223, 432));
        label_2->setMaximumSize(QSize(223, 432));
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::Box);
        label_2->setLineWidth(2);

        verticalLayout_2->addWidget(label_2);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(223, 28));
        pushButton_2->setMaximumSize(QSize(223, 28));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(223, 432));
        label_3->setMaximumSize(QSize(223, 432));
        label_3->setAutoFillBackground(true);
        label_3->setFrameShape(QFrame::Box);
        label_3->setLineWidth(2);

        verticalLayout_3->addWidget(label_3);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(223, 28));
        pushButton_3->setMaximumSize(QSize(223, 28));

        verticalLayout_3->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(SceneWindows);

        QMetaObject::connectSlotsByName(SceneWindows);
    } // setupUi

    void retranslateUi(QWidget *SceneWindows)
    {
        SceneWindows->setWindowTitle(QApplication::translate("SceneWindows", "SceneWindows", Q_NULLPTR));
        label->setText(QApplication::translate("SceneWindows", "<html><head/><body><p>\345\234\272\346\231\257A</p><p>\344\273\213\347\273\215\357\274\232</p><p>1</p><p>1</p><p>1</p><p>1</p><p>1</p><p>1</p><p>1</p><p><img src=\":/MainWindows/D:/\345\233\276\347\211\207/test.jpg\"/></p></body></html>", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("SceneWindows", "PushButton", Q_NULLPTR));
        label_2->setText(QApplication::translate("SceneWindows", "<html><head/><body><p>\345\234\272\346\231\257B<br/>\344\273\213\347\273\215\357\274\232</p><p>\343\200\202\343\200\202\343\200\202\343\200\202</p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SceneWindows", "PushButton", Q_NULLPTR));
        label_3->setText(QApplication::translate("SceneWindows", "<html><head/><body><p>\345\234\272\346\231\257C</p><p>\344\273\213\347\273\215\357\274\232</p><p>......</p></body></html>", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("SceneWindows", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SceneWindows: public Ui_SceneWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEWINDOWS_H
