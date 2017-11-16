#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	sceneWindows = new SceneWindows;
	sceneWindows->show();

	//����ѡ��
	connect(sceneWindows, &SceneWindows::sendSceneSignal1, this, &MainWindows::login1);
	connect(sceneWindows, &SceneWindows::sendSceneSignal2, this, &MainWindows::login2);
	connect(sceneWindows, &SceneWindows::sendSceneSignal3, this, &MainWindows::login3);

	//���������ò�����ʼ��
	initCamera();
	initLens();
	initLS();
	initLD();
	


	//�鿴�������
	connect(ui.buttonCheckRequirement, &QPushButton::clicked, this, &MainWindows::checkRequirement);

	//ȷ������
	connect(ui.buttonAccuracy, &QPushButton::clicked, this, &MainWindows::checkAccuracy);

	//��һ��
	connect(ui.buttonLast, &QPushButton::clicked, this, &MainWindows::toLast);
	//��һ��
	connect(ui.buttonNext, &QPushButton::clicked, this, &MainWindows::toNext);
	

	//ѡ������Ѷ�
	connect(hardChooseWindows, &HardChooseWindows::okSignal, this, &MainWindows::levelOK);
}

/************************************************************************/
/* ����ѡ��                                                          */
/************************************************************************/
void MainWindows::login1() {
	m_iScene = 1;
	initGraphicsView();	//ѡ�񳡾�֮���ٳ�ʼ��ͼƬ
	this->show();
	sceneWindows->close();
}

void MainWindows::login2() {
	m_iScene = 2;
	initGraphicsView();//ѡ�񳡾�֮���ٳ�ʼ��ͼƬ
	this->show();
	sceneWindows->close();
}

void MainWindows::login3() {
	m_iScene = 3;
	initGraphicsView();//ѡ�񳡾�֮���ٳ�ʼ��ͼƬ
	this->show();
	sceneWindows->close();
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

	m_iCamera = index;	//����û�ѡ�񼸺����
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

	m_iLens = index;	//����û�ѡ�񼸺ž�ͷ
}

//��Դѡ���ʼ��
void MainWindows::initLS(){
	ui.comboBoxLightSource->addItem(QStringLiteral("��ѡ��"));
	ui.comboBoxLightSource->addItem(QStringLiteral("��Դ1:MSU-10-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("��Դ2:MSU-30-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("��Դ3:MSU-30��20-SW/BL/GR"));
	connect(ui.comboBoxLightSource,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLS);
}
void MainWindows::boxChangeLS(int index){
	//��ȡ�����ļ�
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	QString chiCun = QStringLiteral("�ߴ磺 ") + config->value("/LightSource" + QString::number(index) + "/chiCun").toString() + QString("<br><br>");
	QString color = QStringLiteral("��ɫ�� ") + config->value("/LightSource" + QString::number(index) + "/color").toString() + QString("<br><br>");
	QString str = chiCun + color;
	ui.labelLightSourceDetail->setText(str);

	m_iLS = index;	//����û�ѡ�񼸺Ź�Դ
}

//��Դ����ѡ��ĳ�ʼ��
void MainWindows::initLD() {
	ui.comboBoxLightDistance->addItem(QStringLiteral("��ѡ��"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("Զ"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("��"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("��"));
	connect(ui.comboBoxLightDistance,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLD);
}
void MainWindows::boxChangeLD(int index) {
	qDebug() << index;
	QString str = QString::number(index);	//QT��int��String��ת��
	QMessageBox msgBox;
	msgBox.setInformativeText(str);
	msgBox.exec();

	m_iLD = index;	//����û�ѡ�񼸺Ź�Դ����
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

//��һ��
void MainWindows::toLast() {
	this->close();
	sceneWindows->show();
	
}

//��һ��
void MainWindows::toNext() {

	bool flag = checkAccuracy();	//�鿴�û�����ľ��Ⱥϸ��
	if (flag==false)
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("����ľ��Ȳ�����ʵ��Ҫ��"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
	}
	else
	{
		//��⾫��ͨ����ѡ��ʵ���Ѷ�
		hardChooseWindows = new HardChooseWindows();
		hardChooseWindows->setWindowTitle(QStringLiteral("�Ѷ�ѡ��"));
		hardChooseWindows->setWindowModality(Qt::ApplicationModal);	//����QWidget����Ϊģ�����ڣ���QWidget����û�д��븸��
		hardChooseWindows->show();
		

	}

	

}

/************************************************************************/
/* ȷ������                                                              */
/************************************************************************/
bool MainWindows::checkAccuracy() {
	
	double inputAccuracy = ui.spinBoxAccuracy->value();	//��ȡ�û�����ľ���
	if (inputAccuracy==NULL&&inputAccuracy==0)
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("�����뾫��"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return false;
	}
	qDebug() << inputAccuracy;

	//��ȡ�����ļ�����ò�ͬ��������ľ���
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	double sceneAccuracy = config->value("/SceneAccuracy" + QString::number(m_iScene) + "/accuracy").toDouble();
	
	//����û����뾫��С�ڳ������辫�ȣ��򷵻�true
	if (inputAccuracy<=sceneAccuracy)
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("���뾫�ȷ���Ҫ��"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return true;
	}
	else
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("����ľ��Ȳ�����ʵ��Ҫ��"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return false;
	}

}

/************************************************************************/
/* ѡ������Ѷ�                                                          */
/************************************************************************/
void MainWindows::levelOK() {
	
}