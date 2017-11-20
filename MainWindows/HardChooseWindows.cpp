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

	//����OK�����ܰ���ֻ��ѡ���ѶȺ���ܰ�
	ui.buttonLevelOk->setEnabled(false);
}

HardChooseWindows::~HardChooseWindows()
{
}

void HardChooseWindows::chooseLevel(QAbstractButton *button){
	qDebug()<< QString("Clicked Button : %1").arg(button->text());	//��ӡ��ѡ��İ�ť����
	qDebug() << myButtonGroup->checkedId();	//��ͨ��checkedIdֱ�Ӽ�����ǰѡ��İ�ťID

	//m_iLevel=-2 �����Ѷ�
	//m_iLevel=-3 �м��Ѷ�
	//m_iLevel=-4 �߼��Ѷ�
	m_iLevel= myButtonGroup->checkedId();

	//����OK�����ܰ���ֻ��ѡ���ѶȺ���ܰ�
	ui.buttonLevelOk->setEnabled(true);
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

//�����Ѷȱ�ʶm_iLevel
int HardChooseWindows::getLevel() {
	return m_iLevel;
}