/********************************************************************************
** Form generated from reading UI file 'MainWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWS_H
#define UI_MAINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowsClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *buttonCheckRequirement;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_3;
    QLabel *labelCamera;
    QGridLayout *gridLayout_4;
    QComboBox *comboBoxCamera;
    QGridLayout *gridLayout_5;
    QLabel *labelCameraDetail;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_7;
    QLabel *labelLens;
    QGridLayout *gridLayout_6;
    QComboBox *comboBoxLens;
    QGridLayout *gridLayout_8;
    QLabel *labelLensDetail;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_9;
    QLabel *labelLightSource;
    QGridLayout *gridLayout_10;
    QComboBox *comboBoxLightSource;
    QGridLayout *gridLayout_11;
    QLabel *labelLightSourceDetail;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_12;
    QLabel *labelLightDistance;
    QGridLayout *gridLayout_13;
    QComboBox *comboBoxLightDistance;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxAccuracy;
    QPushButton *buttonAccuracy;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *buttonLast;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonNext;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowsClass)
    {
        if (MainWindowsClass->objectName().isEmpty())
            MainWindowsClass->setObjectName(QStringLiteral("MainWindowsClass"));
        MainWindowsClass->resize(1024, 793);
        centralWidget = new QWidget(MainWindowsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(740, 10, 261, 643));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonCheckRequirement = new QPushButton(layoutWidget);
        buttonCheckRequirement->setObjectName(QStringLiteral("buttonCheckRequirement"));

        gridLayout_2->addWidget(buttonCheckRequirement, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        labelCamera = new QLabel(layoutWidget);
        labelCamera->setObjectName(QStringLiteral("labelCamera"));
        labelCamera->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(labelCamera, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        comboBoxCamera = new QComboBox(layoutWidget);
        comboBoxCamera->setObjectName(QStringLiteral("comboBoxCamera"));

        gridLayout_4->addWidget(comboBoxCamera, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        labelCameraDetail = new QLabel(layoutWidget);
        labelCameraDetail->setObjectName(QStringLiteral("labelCameraDetail"));
        labelCameraDetail->setFrameShape(QFrame::Box);

        gridLayout_5->addWidget(labelCameraDetail, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        labelLens = new QLabel(layoutWidget);
        labelLens->setObjectName(QStringLiteral("labelLens"));
        labelLens->setFrameShape(QFrame::NoFrame);

        gridLayout_7->addWidget(labelLens, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        comboBoxLens = new QComboBox(layoutWidget);
        comboBoxLens->setObjectName(QStringLiteral("comboBoxLens"));

        gridLayout_6->addWidget(comboBoxLens, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_6);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        labelLensDetail = new QLabel(layoutWidget);
        labelLensDetail->setObjectName(QStringLiteral("labelLensDetail"));
        labelLensDetail->setFrameShape(QFrame::Box);

        gridLayout_8->addWidget(labelLensDetail, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        labelLightSource = new QLabel(layoutWidget);
        labelLightSource->setObjectName(QStringLiteral("labelLightSource"));
        labelLightSource->setFrameShape(QFrame::NoFrame);

        gridLayout_9->addWidget(labelLightSource, 0, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_9);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        comboBoxLightSource = new QComboBox(layoutWidget);
        comboBoxLightSource->setObjectName(QStringLiteral("comboBoxLightSource"));

        gridLayout_10->addWidget(comboBoxLightSource, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_10);


        verticalLayout->addLayout(horizontalLayout_3);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        labelLightSourceDetail = new QLabel(layoutWidget);
        labelLightSourceDetail->setObjectName(QStringLiteral("labelLightSourceDetail"));
        labelLightSourceDetail->setFrameShape(QFrame::Box);

        gridLayout_11->addWidget(labelLightSourceDetail, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_11);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        labelLightDistance = new QLabel(layoutWidget);
        labelLightDistance->setObjectName(QStringLiteral("labelLightDistance"));
        labelLightDistance->setFrameShape(QFrame::NoFrame);

        gridLayout_12->addWidget(labelLightDistance, 0, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_12);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        comboBoxLightDistance = new QComboBox(layoutWidget);
        comboBoxLightDistance->setObjectName(QStringLiteral("comboBoxLightDistance"));

        gridLayout_13->addWidget(comboBoxLightDistance, 0, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_13);


        verticalLayout->addLayout(horizontalLayout_4);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 710, 680));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(740, 660, 254, 30));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        spinBoxAccuracy = new QDoubleSpinBox(layoutWidget1);
        spinBoxAccuracy->setObjectName(QStringLiteral("spinBoxAccuracy"));

        horizontalLayout_5->addWidget(spinBoxAccuracy);

        buttonAccuracy = new QPushButton(layoutWidget1);
        buttonAccuracy->setObjectName(QStringLiteral("buttonAccuracy"));

        horizontalLayout_5->addWidget(buttonAccuracy);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 700, 986, 30));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        buttonLast = new QPushButton(widget);
        buttonLast->setObjectName(QStringLiteral("buttonLast"));
        buttonLast->setMinimumSize(QSize(151, 28));
        buttonLast->setMaximumSize(QSize(151, 28));

        horizontalLayout_6->addWidget(buttonLast);

        horizontalSpacer = new QSpacerItem(668, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        buttonNext = new QPushButton(widget);
        buttonNext->setObjectName(QStringLiteral("buttonNext"));
        buttonNext->setMinimumSize(QSize(151, 28));
        buttonNext->setMaximumSize(QSize(151, 28));

        horizontalLayout_6->addWidget(buttonNext);

        MainWindowsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 26));
        MainWindowsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowsClass->setStatusBar(statusBar);

        retranslateUi(MainWindowsClass);

        QMetaObject::connectSlotsByName(MainWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowsClass)
    {
        MainWindowsClass->setWindowTitle(QApplication::translate("MainWindowsClass", "MainWindows", Q_NULLPTR));
        buttonCheckRequirement->setText(QApplication::translate("MainWindowsClass", "\346\237\245\347\234\213\346\243\200\346\265\213\351\234\200\346\261\202", Q_NULLPTR));
        labelCamera->setText(QApplication::translate("MainWindowsClass", "\347\233\270\346\234\272\357\274\232", Q_NULLPTR));
        labelCameraDetail->setText(QApplication::translate("MainWindowsClass", "<html><head/><body><p>1</p><p>2</p><p>3</p><p>4</p><p><br/></p></body></html>", Q_NULLPTR));
        labelLens->setText(QApplication::translate("MainWindowsClass", "\351\225\234\345\244\264\357\274\232", Q_NULLPTR));
        labelLensDetail->setText(QApplication::translate("MainWindowsClass", "<html><head/><body><p>1</p><p>2</p><p>3</p><p>4</p><p><br/></p></body></html>", Q_NULLPTR));
        labelLightSource->setText(QApplication::translate("MainWindowsClass", "\345\205\211\346\272\220\357\274\232", Q_NULLPTR));
        labelLightSourceDetail->setText(QApplication::translate("MainWindowsClass", "<html><head/><body><p>1</p><p>2</p><p>3</p><p>4</p><p><br/></p></body></html>", Q_NULLPTR));
        labelLightDistance->setText(QApplication::translate("MainWindowsClass", "\345\205\211\346\272\220\350\267\235\347\246\273\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindowsClass", "\346\265\213\351\207\217\347\262\276\345\272\246\357\274\232", Q_NULLPTR));
        buttonAccuracy->setText(QApplication::translate("MainWindowsClass", "\347\241\256\345\256\232", Q_NULLPTR));
        buttonLast->setText(QApplication::translate("MainWindowsClass", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        buttonNext->setText(QApplication::translate("MainWindowsClass", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowsClass: public Ui_MainWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWS_H
