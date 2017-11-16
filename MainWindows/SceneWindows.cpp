#include "SceneWindows.h"

SceneWindows::SceneWindows(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//���Ӳۺ���
	connect(ui.pushButton_1, &QPushButton::clicked, this, &SceneWindows::chooseScene1);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &SceneWindows::chooseScene2);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &SceneWindows::chooseScene3);
}

SceneWindows::~SceneWindows()
{
}

/************************************************************************/
/* ����ѡ��                                                          */
/************************************************************************/
void SceneWindows::chooseScene1() {
	emit sendSceneSignal1();
}
void SceneWindows::chooseScene2() {
	emit sendSceneSignal2();
}
void SceneWindows::chooseScene3() {
	emit sendSceneSignal3();
}