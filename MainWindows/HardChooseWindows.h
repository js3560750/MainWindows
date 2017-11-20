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
	QButtonGroup *myButtonGroup;	//如果没有进行分组，则默认拥有相同父窗体的radio buttons都将具有相互排他性
	int getLevel();

signals:
	void okSignal();
private:
	Ui::HardChooseWindows ui;
	int m_iLevel;

private slots:
	void chooseLevel(QAbstractButton *button);
	void toLast();	//返回键
	void toNext();	//确认键
};
