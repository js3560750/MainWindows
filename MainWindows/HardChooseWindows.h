#pragma once

#include <QWidget>
#include "ui_HardChooseWindows.h"
#include <QAbstractButton>
#include <QDebug>

class HardChooseWindows : public QWidget
{
	Q_OBJECT

public:
	HardChooseWindows(QWidget *parent = Q_NULLPTR);
	~HardChooseWindows();
	QButtonGroup *myButtonGroup;	//���û�н��з��飬��Ĭ��ӵ����ͬ�������radio buttons���������໥������
	int getLevel();

signals:
	void okSignal();
private:
	Ui::HardChooseWindows ui;
	int m_iLevel;

private slots:
	void chooseLevel(QAbstractButton *button);
	void toLast();	//���ؼ�
	void toNext();	//ȷ�ϼ�
};
