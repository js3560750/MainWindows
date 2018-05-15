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
	SceneWindows *sceneWindows;	//����ʼ���Ļ�ָ��ֵ�ĳ�ʼֵ����ֵ
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
	int m_iScene;	//�û�ѡ��ĳ���:1��Ӧpicture1,2��Ӧpicture2,3��Ӧpicture3
	int m_iCamera;	//�û�ѡ������
	int m_iLens;	//�û�ѡ��ľ�ͷ
	int m_iLS;		//�û�ѡ��Ĺ�Դ
	int m_iLD;		//�û�ѡ��Ĺ�Դ����
	
	int m_iGSFilter;	//�м��Ѷȸ�˹�˲����ò���

signals:
	void GSFilterSignal(int);

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

	//��һ�������س���ѡ��
	void toLast();
	//��һ��
	void toNext();

	//ѡ������Ѷ�
	void levelOK();

	//�ָ�Ϊԭͼ
	void imgRevert();

	//�˲�
	void FKFilter();
	void JZFilter();
	void GSFilter();
	void GSFilter_msg();
	void GSFilter_parameter();	//�м��Ѷ��õĿɵ����˲�
	void commonFilter(QString str);	//�˲��Ĺ�������

	//��̬ѧ
	void imgDilate();
	void imgErode();
	void imgOpenOperation();
	void imgCloseOperation();
	void commonOperation(QString str);//��̬ѧ��������

	//��ֵ��
	void imgThreshold_1();
	void imgThreshold_2();

	//��Ե���
	void imgEdgeDetect_1();
	void imgEdgeDetect_2();
	void imgEdgeDetect_3();
	void commonEdgeDetect(QString str);	//��Ե��⹫������

};
