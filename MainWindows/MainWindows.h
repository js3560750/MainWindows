#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindows.h"
#include "SceneWindows.h"
#include "HardChooseWindows.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QGraphicsView>

class MainWindows : public QMainWindow
{
	Q_OBJECT

public:
	MainWindows(QWidget *parent = Q_NULLPTR);
	SceneWindows *sceneWindows;
	QDialog *dialog;
	HardChooseWindows *hardChooseWindows;

	void initCamera();
	void initLens();
	void initLS();
	void initLD();
	void initGraphicsView();

private:
	Ui::MainWindowsClass ui;
	int m_iScene;	//用户选择的场景
	int m_iCamera;	//用户选择的相机
	int m_iLens;	//用户选择的镜头
	int m_iLS;		//用户选择的光源
	int m_iLD;		//用户选择的光源距离

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

	//上一步
	void toLast();
	//下一步
	void toNext();

	//选择好了难度
	void levelOK();

};
