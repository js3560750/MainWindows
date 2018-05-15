#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindows.h"
#include "SceneWindows.h"
#include "HardChooseWindows.h"
#include "LevelEasy.h"
#include "LevelMiddle.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QGraphicsView>

#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp> 
#include "opencv2/imgproc/imgproc.hpp"

class MainWindows : public QMainWindow
{
	Q_OBJECT

public:
	MainWindows(QWidget *parent = Q_NULLPTR);
	SceneWindows *sceneWindows;	//不初始化的话指针值的初始值是乱值
	QDialog *dialog;
	HardChooseWindows *hardChooseWindows;
	LevelEasy *levelEasyWindows;
	LevelMiddle *levelMiddleWindows;

	void initCamera();
	void initLens();
	void initLS();
	void initLD();
	void initGraphicsView();

private:
	Ui::MainWindowsClass ui;
	int m_iScene;	//用户选择的场景:1对应picture1,2对应picture2,3对应picture3
	int m_iCamera;	//用户选择的相机
	int m_iLens;	//用户选择的镜头
	int m_iLS;		//用户选择的光源
	int m_iLD;		//用户选择的光源距离
	
	int m_iGSFilter;	//中级难度高斯滤波所用参数

signals:
	void GSFilterSignal(int);

private slots:
	//场景选择
	void login1();
	void login2();
	void login3();

	//点击查看检测需求
	void checkRequirement();

	//相机选择的变化
	void boxChangeCamera(int);
	//镜头选择的变化
	void boxChangeLens(int);
	//光源选择的变化
	void boxChangeLS(int);
	//光源距离选择的变化
	void boxChangeLD(int);

	//确定精度
	bool checkAccuracy();

	//上一步（返回场景选择）
	void toLast();
	//下一步
	void toNext();

	//选择好了难度
	void levelOK();

	//恢复为原图
	void imgRevert();

	//滤波
	void FKFilter();
	void JZFilter();
	void GSFilter();
	void GSFilter_msg();
	void GSFilter_parameter();	//中级难度用的可调参滤波
	void commonFilter(QString str);	//滤波的公共函数

	//形态学
	void imgDilate();
	void imgErode();
	void imgOpenOperation();
	void imgCloseOperation();
	void commonOperation(QString str);//形态学公共函数

	//二值化
	void imgThreshold_1();
	void imgThreshold_2();

	//边缘检测
	void imgEdgeDetect_1();
	void imgEdgeDetect_2();
	void imgEdgeDetect_3();
	void commonEdgeDetect(QString str);	//边缘检测公共函数

};
