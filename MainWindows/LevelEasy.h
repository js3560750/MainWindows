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
	void revertSignal();	//还原信号

	void fkFilterSignal();	//滤波信号
	void jzFilterSignal();
	void gsFilterSignal();

	void dilateSignal();	//形态学信号
	void erodeSignal();
	void openOperationSignal();
	void closeOperationSignal();

	void thresholdSignal_1();	//二值化
	void thresholdSignal_2();

	void edgeDetectSignal_1();	//边缘检测
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
