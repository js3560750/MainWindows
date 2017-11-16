#pragma once

#include <QWidget>
#include "ui_SceneWindows.h"

class SceneWindows : public QWidget
{
	Q_OBJECT

public:
	SceneWindows(QWidget *parent = Q_NULLPTR);
	~SceneWindows();


private:
	Ui::SceneWindows ui;

signals:
	void sendSceneSignal1();
	void sendSceneSignal2();
	void sendSceneSignal3();

private slots:
	void chooseScene1();
	void chooseScene2();
	void chooseScene3();
	
};
