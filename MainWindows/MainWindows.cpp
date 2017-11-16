#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	sceneWindwos = new SceneWindows;
	sceneWindwos->show();

	//场景选择
	connect(sceneWindwos, &SceneWindows::sendSceneSignal1, this, &MainWindows::login1);
	connect(sceneWindwos, &SceneWindows::sendSceneSignal2, this, &MainWindows::login2);
	connect(sceneWindwos, &SceneWindows::sendSceneSignal3, this, &MainWindows::login3);

	//各场景公用参数初始化
	initCamera();
	initLens();
	initLS();
	initLD();
	


	//查看检测需求
	connect(ui.buttonCheckRequirement, &QPushButton::clicked, this, &MainWindows::checkRequirement);
}

/************************************************************************/
/* 场景选择                                                          */
/************************************************************************/
void MainWindows::login1() {
	m_iScene = 1;
	initGraphicsView();	//选择场景之后再初始化图片
	this->show();
	sceneWindwos->close();
}

void MainWindows::login2() {
	m_iScene = 2;
	initGraphicsView();//选择场景之后再初始化图片
	this->show();
	sceneWindwos->close();
}

void MainWindows::login3() {
	m_iScene = 3;
	initGraphicsView();//选择场景之后再初始化图片
	this->show();
	sceneWindwos->close();
}

/************************************************************************/
/* 查看检测需求                                                         */
/************************************************************************/
void MainWindows::checkRequirement() {

	//读取配置文件
	QSettings *config= new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	//根据选择的场景来读取不同的配置文件
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


	//用QDialog弹出对话框，没有QMessageBox简单，虽然QMessageBox是继承的QDialog
	QDialog dialog(this);
	dialog.resize(300, 300);
	dialog.setWindowTitle(QStringLiteral("检测需求"));
	QLabel *label = new QLabel(&dialog);	//要把QLabel放在QDialog中来显示文字，QDialog类似一个QMainWindows
	label->setText(str);
	dialog.exec();
}

/************************************************************************/
/* 初始化                                                        */
/************************************************************************/
//相机选择初始化  
void MainWindows::initCamera() {
	ui.comboBoxCamera->addItem(QStringLiteral("请选择"));
	ui.comboBoxCamera->addItem(QStringLiteral("相机1:MER-531-20GC-P"));
	ui.comboBoxCamera->addItem(QStringLiteral("相机2:MER-231-41GM-P"));
	ui.comboBoxCamera->addItem(QStringLiteral("相机3:MER-030-20GC-P"));
	
	//将下拉选项的改变与槽函数连接
	//void (QComboBox:: *currentIndexChangedSignal)(int) = &QComboBox::currentIndexChanged;
	connect(ui.comboBoxCamera, 
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), 
		this, 
		&MainWindows::boxChangeCamera);
}

void MainWindows::boxChangeCamera(int index) {
	//qDebug() << index;
	//QString str1 = QString::number(index);	//QT中int和String的转型
	//QMessageBox msgBox;
	//msgBox.setInformativeText(str1);
	//msgBox.exec();
	//读取配置文件
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	QString fenBianLv = QStringLiteral("分辨率： ") + config->value("/Camera" + QString::number(index) + "/fenbianlv").toString()+QString("<br><br>");
	QString zhenLv = QStringLiteral("帧率： ") + config->value("/Camera" + QString::number(index) + "/zhenLv").toString() + QString("<br><br>");
	QString xiangSuChiCun = QStringLiteral("像素尺寸： ") + config->value("/Camera" + QString::number(index) + "/xiangSuChiCun").toString() + QString("<br><br>");
	QString str = fenBianLv + zhenLv + xiangSuChiCun;
	ui.labelCameraDetail->setText(str);
}

//镜头选择的变化
void MainWindows::initLens() {
	ui.comboBoxLens->addItem(QStringLiteral("请选择"));
	ui.comboBoxLens->addItem(QStringLiteral("镜头1:M3Z1228C-MP"));
	ui.comboBoxLens->addItem(QStringLiteral("镜头2:H2Z0414C-MP"));
	ui.comboBoxLens->addItem(QStringLiteral("镜头3:H5Z2518C-MP"));
	ui.comboBoxLens->addItem(QStringLiteral("镜头4:A4Z1214CS"));
	ui.comboBoxLens->addItem(QStringLiteral("镜头5:T3Z0312CS"));
	connect(ui.comboBoxLens,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLens);
}

void MainWindows::boxChangeLens(int index) {
	//读取配置文件
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	QString baMianChiCun = QStringLiteral("靶面尺寸： ") + config->value("/Lens" + QString::number(index) + "/baMianChiCun").toString() + QString("<br><br>");
	QString jiaoJu = QStringLiteral("焦距： ") + config->value("/Lens" + QString::number(index) + "/jiaoJu").toString() + QString("<br><br>");
	QString chengXiangChiCun = QStringLiteral("最大成像尺寸： ") + config->value("/Lens" + QString::number(index) + "/chengXiangChiCun").toString() + QString("<br><br>");
	QString juLi = QStringLiteral("工作距离： ") + config->value("/Lens" + QString::number(index) + "/juLi").toString() + QString("<br><br>");
	QString str = baMianChiCun + jiaoJu + chengXiangChiCun+ juLi;
	ui.labelLensDetail->setText(str);
}

//光源选择初始化
void MainWindows::initLD(){
	ui.comboBoxLightSource->addItem(QStringLiteral("请选择"));
	ui.comboBoxLightSource->addItem(QStringLiteral("光源1:MSU-10-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("光源2:MSU-30-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("光源3:MSU-30×20-SW/BL/GR"));
	connect(ui.comboBoxLightSource,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLD);
}
void MainWindows::boxChangeLD(int index){
	//读取配置文件
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	QString chiCun = QStringLiteral("尺寸： ") + config->value("/LightSource" + QString::number(index) + "/chiCun").toString() + QString("<br><br>");
	QString color = QStringLiteral("颜色： ") + config->value("/LightSource" + QString::number(index) + "/color").toString() + QString("<br><br>");
	QString str = chiCun + color;
	ui.labelLightSourceDetail->setText(str);
}

//光源距离选择的初始化
void MainWindows::initLS() {
	ui.comboBoxLightDistance->addItem(QStringLiteral("请选择"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("远"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("中"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("近"));
	connect(ui.comboBoxLightDistance,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLS);
}
void MainWindows::boxChangeLS(int index) {
	qDebug() << index;
	QString str = QString::number(index);	//QT中int和String的转型
	QMessageBox msgBox;
	msgBox.setInformativeText(str);
	msgBox.exec();
}

//图片初始化
void MainWindows::initGraphicsView() {
	//读取配置文件
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
									//根据选择的场景来读取不同的配置文件
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