#pragma once

#include <QWidget>
#include "ui_LevelEasy.h"



class LevelEasy : public QWidget
{
	Q_OBJECT

public:
	LevelEasy(QWidget *parent = Q_NULLPTR);
	~LevelEasy();

signals:
	void revertSignal();	//��ԭ�ź�

	void fkFilterSignal();	//�˲��ź�
	void jzFilterSignal();
	void gsFilterSignal();

	void dilateSignal();	//��̬ѧ�ź�
	void erodeSignal();
	void openOperationSignal();
	void closeOperationSignal();

	void thresholdSignal_1();	//��ֵ��
	void thresholdSignal_2();

	void edgeDetectSignal_1();	//��Ե���
	void edgeDetectSignal_2();
	void edgeDetectSignal_3();

private:
	Ui::LevelEasy ui;

private slots:
	void sendRevert();

	void sendFKFilter();
	void sendJZFilter();
	void sendGSFilter();

	void sendDilate();
	void sendErode();
	void sendOpenOperation();
	void sendCloseOperation();
	
	void sendThreshold_1();
	void sendThreshold_2();

	void sendEdgeDetect_1();
	void sendEdgeDetect_2();
	void sendEdgeDetect_3();
};
