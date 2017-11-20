#pragma once

#include <QWidget>
#include "ui_LevelMiddle.h"

class LevelMiddle : public QWidget
{
	Q_OBJECT

public:
	LevelMiddle(QWidget *parent = Q_NULLPTR);
	~LevelMiddle();

signals:
	void revertSignal();	//还原信号

	void gsFilterSignal();	//滤波信号

private:
	Ui::LevelMiddle ui;

private slots:
	void sendRevert();

	void sendGSFilter();

};
