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
	void revertSignal();	//��ԭ�ź�

	void gsFilterSignal();	//�˲��ź�

private:
	Ui::LevelMiddle ui;

private slots:
	void sendRevert();

	void sendGSFilter();

};
