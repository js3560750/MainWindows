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

	//设置OK键不能按，只有选了难度后才能按
	ui.buttonLevelOk->setEnabled(false);
}

HardChooseWindows::~HardChooseWindows()
{
}

void HardChooseWindows::chooseLevel(QAbstractButton *button){
	qDebug()<< QString("Clicked Button : %1").arg(button->text());	//打印出选择的按钮名称
	qDebug() << myButtonGroup->checkedId();	//可通过checkedId直接检查出当前选择的按钮ID

	//m_iLevel=-2 初级难度
	//m_iLevel=-3 中级难度
	//m_iLevel=-4 高级难度
	m_iLevel= myButtonGroup->checkedId();

	//设置OK键不能按，只有选了难度后才能按
	ui.buttonLevelOk->setEnabled(true);
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

//返回难度标识m_iLevel
int HardChooseWindows::getLevel() {
	return m_iLevel;
}