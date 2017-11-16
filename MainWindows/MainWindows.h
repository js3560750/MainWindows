#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindows.h"
#include "SceneWindows.h"
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
	SceneWindows *sceneWindwos;
	QDialog *dialog;

	void initCamera();
	void initLens();
	void initLS();
	void initLD();
	void initGraphicsView();

private:
	Ui::MainWindowsClass ui;
	int m_iScene;

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

};
