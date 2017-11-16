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
	//����ѡ��
	void login1();
	void login2();
	void login3();

	//����鿴�������
	void checkRequirement();

	//���ѡ��ı仯
	void boxChangeCamera(int);
	//��ͷѡ��ı仯
	void boxChangeLens(int);
	//��Դѡ��ı仯
	void boxChangeLS(int);
	//��Դ����ѡ��ı仯
	void boxChangeLD(int);

};
