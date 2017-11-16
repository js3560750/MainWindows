#include "HardChooseWindows.h"

HardChooseWindows::HardChooseWindows(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//建立按钮组
	myButtonGroup = new QButtonGroup(this);
	//设置互斥
	myButtonGroup->setExclusive(true);
	//添加单选按钮到按钮组
	myButtonGroup->addButton(ui.radioButtonEasyLevel);
	myButtonGroup->addButton(ui.radioButtonMiddleLevel);
	myButtonGroup->addButton(ui.radioButtonHighLevel);
	//连接槽信号
	connect(myButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(chooseLevel(QAbstractButton*)));
	

	connect(ui.buttonLevelReturn, &QPushButton::clicked, this, &HardChooseWindows::toLast);
	connect(ui.buttonLevelOk, &QPushButton::clicked, this, &HardChooseWindows::toNext);
}

HardChooseWindows::~HardChooseWindows()
{
}

void HardChooseWindows::chooseLevel(QAbstractButton *button){
	qDebug()<< QString("Clicked Button : %1").arg(button->text());
	qDebug() << myButtonGroup->checkedId();	//可通过checkedId直接检查出当前选择的按钮ID
}

//返回键
void HardChooseWindows::toLast() {
	this->close();

}

//确认键
void HardChooseWindows::toNext() {
	this->close();
	emit okSignal();
}