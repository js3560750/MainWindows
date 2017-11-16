#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	sceneWindwos = new SceneWindows;
	sceneWindwos->show();

	//����ѡ��
	connect(sceneWindwos, &SceneWindows::sendSceneSignal1, this, &MainWindows::login1);
	connect(sceneWindwos, &SceneWindows::sendSceneSignal2, this, &MainWindows::login2);
	connect(sceneWindwos, &SceneWindows::sendSceneSignal3, this, &MainWindows::login3);

	//���������ò�����ʼ��
	initCamera();
	initLens();
	initLS();
	initLD();
	


	//�鿴�������
	connect(ui.buttonCheckRequirement, &QPushButton::clicked, this, &MainWindows::checkRequirement);
}

/************************************************************************/
/* ����ѡ��                                                          */
/************************************************************************/
void MainWindows::login1() {
	m_iScene = 1;
	initGraphicsView();	//ѡ�񳡾�֮���ٳ�ʼ��ͼƬ
	this->show();
	sceneWindwos->close();
}

void MainWindows::login2() {
	m_iScene = 2;
	initGraphicsView();//ѡ�񳡾�֮���ٳ�ʼ��ͼƬ
	this->show();
	sceneWindwos->close();
}

void MainWindows::login3() {
	m_iScene = 3;
	initGraphicsView();//ѡ�񳡾�֮���ٳ�ʼ��ͼƬ
	this->show();
	sceneWindwos->close();
}

/************************************************************************/
/* �鿴�������                                                         */
/************************************************************************/
void MainWindows::checkRequirement() {

	//��ȡ�����ļ�
	QSettings *config= new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	//����ѡ��ĳ�������ȡ��ͬ�������ļ�
	QString str;
	if (m_iScene==1)
	{
		str = config->value("/checkRequirement1/text").toString();
	}
	else if (m_iScene==2)
	{
		str = config->value("/checkRequirement2/text").toString();
	}
	else if (m_iScene==3)
	{
		str = config->value("/checkRequirement3/text").toString();
	}
	else {
		return;
	}


	//��QDialog�����Ի���û��QMessageBox�򵥣���ȻQMessageBox�Ǽ̳е�QDialog
	QDialog dialog(this);
	dialog.resize(300, 300);
	dialog.setWindowTitle(QStringLiteral("�������"));
	QLabel *label = new QLabel(&dialog);	//Ҫ��QLabel����QDialog������ʾ���֣�QDialog����һ��QMainWindows
	label->setText(str);
	dialog.exec();
}

/************************************************************************/
/* ��ʼ��                                                        */
/************************************************************************/
//���ѡ���ʼ��  
void MainWindows::initCamera() {
	ui.comboBoxCamera->addItem(QStringLiteral("��ѡ��"));
	ui.comboBoxCamera->addItem(QStringLiteral("���1:MER-531-20GC-P"));
	ui.comboBoxCamera->addItem(QStringLiteral("���2:MER-231-41GM-P"));
	ui.comboBoxCamera->addItem(QStringLiteral("���3:MER-030-20GC-P"));
	
	//������ѡ��ĸı���ۺ�������
	//void (QComboBox:: *currentIndexChangedSignal)(int) = &QComboBox::currentIndexChanged;
	connect(ui.comboBoxCamera, 
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), 
		this, 
		&MainWindows::boxChangeCamera);
}

void MainWindows::boxChangeCamera(int index) {
	//qDebug() << index;
	//QString str1 = QString::number(index);	//QT��int��String��ת��
	//QMessageBox msgBox;
	//msgBox.setInformativeText(str1);
	//msgBox.exec();
	//��ȡ�����ļ�
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	QString fenBianLv = QStringLiteral("�ֱ��ʣ� ") + config->value("/Camera" + QString::number(index) + "/fenbianlv").toString()+QString("<br><br>");
	QString zhenLv = QStringLiteral("֡�ʣ� ") + config->value("/Camera" + QString::number(index) + "/zhenLv").toString() + QString("<br><br>");
	QString xiangSuChiCun = QStringLiteral("���سߴ磺 ") + config->value("/Camera" + QString::number(index) + "/xiangSuChiCun").toString() + QString("<br><br>");
	QString str = fenBianLv + zhenLv + xiangSuChiCun;
	ui.labelCameraDetail->setText(str);
}

//��ͷѡ��ı仯
void MainWindows::initLens() {
	ui.comboBoxLens->addItem(QStringLiteral("��ѡ��"));
	ui.comboBoxLens->addItem(QStringLiteral("��ͷ1:M3Z1228C-MP"));
	ui.comboBoxLens->addItem(QStringLiteral("��ͷ2:H2Z0414C-MP"));
	ui.comboBoxLens->addItem(QStringLiteral("��ͷ3:H5Z2518C-MP"));
	ui.comboBoxLens->addItem(QStringLiteral("��ͷ4:A4Z1214CS"));
	ui.comboBoxLens->addItem(QStringLiteral("��ͷ5:T3Z0312CS"));
	connect(ui.comboBoxLens,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLens);
}

void MainWindows::boxChangeLens(int index) {
	//��ȡ�����ļ�
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	QString baMianChiCun = QStringLiteral("����ߴ磺 ") + config->value("/Lens" + QString::number(index) + "/baMianChiCun").toString() + QString("<br><br>");
	QString jiaoJu = QStringLiteral("���ࣺ ") + config->value("/Lens" + QString::number(index) + "/jiaoJu").toString() + QString("<br><br>");
	QString chengXiangChiCun = QStringLiteral("������ߴ磺 ") + config->value("/Lens" + QString::number(index) + "/chengXiangChiCun").toString() + QString("<br><br>");
	QString juLi = QStringLiteral("�������룺 ") + config->value("/Lens" + QString::number(index) + "/juLi").toString() + QString("<br><br>");
	QString str = baMianChiCun + jiaoJu + chengXiangChiCun+ juLi;
	ui.labelLensDetail->setText(str);
}

//��Դѡ���ʼ��
void MainWindows::initLD(){
	ui.comboBoxLightSource->addItem(QStringLiteral("��ѡ��"));
	ui.comboBoxLightSource->addItem(QStringLiteral("��Դ1:MSU-10-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("��Դ2:MSU-30-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("��Դ3:MSU-30��20-SW/BL/GR"));
	connect(ui.comboBoxLightSource,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLD);
}
void MainWindows::boxChangeLD(int index){
	//��ȡ�����ļ�
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	QString chiCun = QStringLiteral("�ߴ磺 ") + config->value("/LightSource" + QString::number(index) + "/chiCun").toString() + QString("<br><br>");
	QString color = QStringLiteral("��ɫ�� ") + config->value("/LightSource" + QString::number(index) + "/color").toString() + QString("<br><br>");
	QString str = chiCun + color;
	ui.labelLightSourceDetail->setText(str);
}

//��Դ����ѡ��ĳ�ʼ��
void MainWindows::initLS() {
	ui.comboBoxLightDistance->addItem(QStringLiteral("��ѡ��"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("Զ"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("��"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("��"));
	connect(ui.comboBoxLightDistance,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLS);
}
void MainWindows::boxChangeLS(int index) {
	qDebug() << index;
	QString str = QString::number(index);	//QT��int��String��ת��
	QMessageBox msgBox;
	msgBox.setInformativeText(str);
	msgBox.exec();
}

//ͼƬ��ʼ��
void MainWindows::initGraphicsView() {
	//��ȡ�����ļ�
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
									//����ѡ��ĳ�������ȡ��ͬ�������ļ�
	QString str;
	if (m_iScene == 1)
	{
		str = config->value("/pictureUrl1/url").toString();
	}
	else if (m_iScene == 2)
	{
		str = config->value("/pictureUrl2/url").toString();
	}
	else if (m_iScene == 3)
	{
		str = config->value("/pictureUrl3/url").toString();
	}
	else {
		return;
	}
	qDebug() << str;
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(str));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}