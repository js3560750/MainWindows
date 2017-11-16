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
	int m_iScene;	//�û�ѡ��ĳ���
	int m_iCamera;	//�û�ѡ������
	int m_iLens;	//�û�ѡ��ľ�ͷ
	int m_iLS;		//�û�ѡ��Ĺ�Դ
	int m_iLD;		//�û�ѡ��Ĺ�Դ����

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

	//ȷ������
	bool checkAccuracy();

	//��һ��
	void toLast();
	//��һ��
	void toNext();

	//ѡ������Ѷ�
	void levelOK();

};
