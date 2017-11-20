#include "LevelEasy.h"


LevelEasy::LevelEasy(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//恢复为原图
	connect(ui.buttonRevert, &QPushButton::clicked, this, &LevelEasy::sendRevert);
	
	//滤波
	connect(ui.buttonFKFilter, &QPushButton::clicked, this, &LevelEasy::sendFKFilter);
	connect(ui.buttonJZFilter, &QPushButton::clicked, this, &LevelEasy::sendJZFilter);
	connect(ui.buttonGSFilter, &QPushButton::clicked, this, &LevelEasy::sendGSFilter);

	//形态学操作
	connect(ui.buttonDilate, &QPushButton::clicked, this, &LevelEasy::sendDilate);
	connect(ui.buttonErode, &QPushButton::clicked, this, &LevelEasy::sendErode);
	connect(ui.buttonOpenOperation, &QPushButton::clicked, this, &LevelEasy::sendOpenOperation);
	connect(ui.buttonCloseOperation, &QPushButton::clicked, this, &LevelEasy::sendCloseOperation);

	//二值化
	connect(ui.buttonThreshold, &QPushButton::clicked, this, &LevelEasy::sendThreshold_1);
	connect(ui.buttonAdaptiveThreshold, &QPushButton::clicked, this, &LevelEasy::sendThreshold_2);

	//边缘检测
	connect(ui.buttonCanny, &QPushButton::clicked, this, &LevelEasy::sendEdgeDetect_1);
	connect(ui.buttonSobel, &QPushButton::clicked, this, &LevelEasy::sendEdgeDetect_2);
	connect(ui.buttonLaplace, &QPushButton::clicked, this, &LevelEasy::sendEdgeDetect_3);
}

LevelEasy::~LevelEasy()
{
}

//在MainWindows.cpp中接受这些信号
void LevelEasy::sendFKFilter() {
	emit fkFilterSignal();
}

void LevelEasy::sendJZFilter() {
emit jzFilterSignal();
}
void LevelEasy::sendGSFilter() {
emit gsFilterSignal();
}

void LevelEasy::sendRevert() {
	emit revertSignal();
}

void LevelEasy::sendDilate() {
	emit dilateSignal();
}
void LevelEasy::sendErode() {
	emit erodeSignal();
}
void LevelEasy::sendOpenOperation() {
	emit openOperationSignal();
}
void LevelEasy::sendCloseOperation() {
	emit closeOperationSignal();
}
void LevelEasy::sendThreshold_1() {
	emit thresholdSignal_1();
}
void LevelEasy::sendThreshold_2() {
	emit thresholdSignal_2();
}
void LevelEasy::sendEdgeDetect_1() {
	emit edgeDetectSignal_1();
}
void LevelEasy::sendEdgeDetect_2() {
	emit edgeDetectSignal_2();
}
void LevelEasy::sendEdgeDetect_3() {
	emit edgeDetectSignal_3();
}