#include "HardChooseWindows.h"

HardChooseWindows::HardChooseWindows(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//������ť��
	myButtonGroup = new QButtonGroup(this);
	//���û���
	myButtonGroup->setExclusive(true);
	//��ӵ�ѡ��ť����ť��
	myButtonGroup->addButton(ui.radioButtonEasyLevel);
	myButtonGroup->addButton(ui.radioButtonMiddleLevel);
	myButtonGroup->addButton(ui.radioButtonHighLevel);
	//���Ӳ��ź�
	connect(myButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(chooseLevel(QAbstractButton*)));
	

	connect(ui.buttonLevelReturn, &QPushButton::clicked, this, &HardChooseWindows::toLast);
	connect(ui.buttonLevelOk, &QPushButton::clicked, this, &HardChooseWindows::toNext);
}

HardChooseWindows::~HardChooseWindows()
{
}

void HardChooseWindows::chooseLevel(QAbstractButton *button){
	qDebug()<< QString("Clicked Button : %1").arg(button->text());
	qDebug() << myButtonGroup->checkedId();	//��ͨ��checkedIdֱ�Ӽ�����ǰѡ��İ�ťID
}

//���ؼ�
void HardChooseWindows::toLast() {
	this->close();

}

//ȷ�ϼ�
void HardChooseWindows::toNext() {
	this->close();
	emit okSignal();
}