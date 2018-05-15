#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	
	//����ֵ��������ͷ�ļ��и���ֵ��ͷ�ļ���ֻ������
	m_iGSFilter = 0;	//�м��Ѷȸ�˹�˲����ò���
	sceneWindows = nullptr;	//����ʼ���Ļ�ָ��ֵ�ĳ�ʼֵ����ֵ
	dialog = nullptr;
	hardChooseWindows = NULL;	
	//NULL�����ͣ�nullptr������,������nullptr_t������Ӧ��ʹ��nullptr��������Ǳ�����ʵ��nullptr��ʱ������˸���ϸ�ڵĿ��ǣ���ȻҲ����ʹ���߸���ı��ϣ�
	/*
	void f(void*)
{
}

void f(int)
{
}

int main()
{
	f(0); // what function will be called?
}

��������nullptr���������͵õ���������������˳���ĵ���void f(void*)����汾��
	*/
	levelEasyWindows = nullptr;
	levelMiddleWindows = nullptr;



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

	//��һ�������س���ѡ��
	connect(ui.buttonLast, &QPushButton::clicked, this, &MainWindows::toLast);
	//��һ��
	connect(ui.buttonNext, &QPushButton::clicked, this, &MainWindows::toNext);
	ui.buttonNext->setEnabled(false);	//ֻ�о���ͨ������ܵ����һ��
	

	
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
	delete config;
	config = NULL;

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

	delete config;
	config = NULL;
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

	delete config;
	config = NULL;
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

	delete config;
	config = NULL;
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

	//����GraphicsView��ǰͼƬΪcurrentImage.jpg
	QImage currentImage;
	currentImage.load(str);	
	currentImage.save("./images/currentImage.jpg", "JPG");




	delete config;
	config = NULL;


	
}

//��һ�������س���ѡ��
void MainWindows::toLast() {
	this->close();
	//��������˳��и߼�ʵ����棬���س���ѡ��ʱ��Ҫ�ر���Щ����
	if (NULL!=levelEasyWindows) {
		levelEasyWindows->close();
	}
	if (NULL != levelMiddleWindows) {
		levelMiddleWindows->close();
	}
	if (ui.buttonNext->isHidden())
	{
		ui.buttonNext->setHidden(false);
	}

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
		ui.buttonNext->setEnabled(false);
	}
	else
	{
		//��⾫��ͨ����ѡ��ʵ���Ѷ�
		hardChooseWindows = new HardChooseWindows();
		hardChooseWindows->setWindowTitle(QStringLiteral("�Ѷ�ѡ��"));
		hardChooseWindows->setWindowModality(Qt::ApplicationModal);	//����QWidget����Ϊģ�����ڣ���QWidget����û�д��븸��
		hardChooseWindows->show();

		//�½�����֮�������Ӳۺ�����ѡ������Ѷ�
		connect(hardChooseWindows, &HardChooseWindows::okSignal, this, &MainWindows::levelOK);
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
	
	delete config;
	config = NULL;

	//����û����뾫��С�ڳ������辫�ȣ��򷵻�true
	if (inputAccuracy<=sceneAccuracy)
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("���뾫�ȷ���Ҫ��"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();

		ui.buttonNext->setEnabled(true);	//ֻ�о���ͨ������ܵ����һ��
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
	
	int level = hardChooseWindows->getLevel();
	
	//Level=-2 �����Ѷ�
	//Level=-3 �м��Ѷ�
	//Level=-4 �߼��Ѷ�
	
	if (level==-2)	//���Ѷ�
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("��ѡ���˳����Ѷ�"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		//ui.buttonLast->setHidden(true);	//������һ����ť
		ui.buttonNext->setHidden(true);	//������һ����ť

		//��������ʵ����棬�����������ڵ��������ͷ�ȵ�ѡ�����
		levelEasyWindows = new LevelEasy(this);
		levelEasyWindows->setAutoFillBackground(true);	
		levelEasyWindows->setGeometry(740, 15, 270, 700);
		levelEasyWindows->show();
		
		//�ָ�Ϊԭͼ
		connect(levelEasyWindows, &LevelEasy::revertSignal, this, &MainWindows::imgRevert);
		//�˲�
		connect(levelEasyWindows, &LevelEasy::fkFilterSignal, this, &MainWindows::FKFilter);
		connect(levelEasyWindows, &LevelEasy::jzFilterSignal, this, &MainWindows::JZFilter);
		connect(levelEasyWindows, &LevelEasy::gsFilterSignal, this, &MainWindows::GSFilter);
		//��̬ѧ
		connect(levelEasyWindows, &LevelEasy::dilateSignal, this, &MainWindows::imgDilate);
		connect(levelEasyWindows, &LevelEasy::erodeSignal, this, &MainWindows::imgErode);
		connect(levelEasyWindows, &LevelEasy::openOperationSignal, this, &MainWindows::imgOpenOperation);
		connect(levelEasyWindows, &LevelEasy::closeOperationSignal, this, &MainWindows::imgCloseOperation);
		//��ֵ��
		connect(levelEasyWindows, &LevelEasy::thresholdSignal_1, this, &MainWindows::imgThreshold_1);
		connect(levelEasyWindows, &LevelEasy::thresholdSignal_2, this, &MainWindows::imgThreshold_2);
		//��Ե���
		connect(levelEasyWindows, &LevelEasy::edgeDetectSignal_1, this, &MainWindows::imgEdgeDetect_1);
		connect(levelEasyWindows, &LevelEasy::edgeDetectSignal_2, this, &MainWindows::imgEdgeDetect_2);
		connect(levelEasyWindows, &LevelEasy::edgeDetectSignal_3, this, &MainWindows::imgEdgeDetect_3);
	}
	else if (level==-3)	//�м��Ѷ�
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("��ѡ�����м��Ѷ�"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		//ui.buttonLast->setHidden(true);	//������һ����ť
		ui.buttonNext->setHidden(true);	//������һ����ť

		//��������ʵ����棬�����������ڵ��������ͷ�ȵ�ѡ�����
		levelMiddleWindows = new LevelMiddle(this);
		levelMiddleWindows->setAutoFillBackground(true);
		levelMiddleWindows->setGeometry(740, 15, 270, 700);
		levelMiddleWindows->show();

		//�ָ�Ϊԭͼ
		connect(levelMiddleWindows, &LevelMiddle::revertSignal, this, &MainWindows::imgRevert);
		//�˲�
		connect(levelMiddleWindows, &LevelMiddle::gsFilterSignal, this, &MainWindows::GSFilter_msg);
	}

}

/************************************************************************/
/* ���ѶȲ������                                                      */
/************************************************************************/
//�ָ�Ϊԭͼ
void MainWindows::imgRevert() {
	initGraphicsView();
}

//�˲�
void MainWindows::FKFilter() {
	
	commonFilter("FKFilter");

}

void MainWindows::JZFilter() {
	commonFilter("JZFilter");
}

void MainWindows::GSFilter() {
	commonFilter("GSFilter");
}

void MainWindows::commonFilter(QString str) {
	//�ȶ�ȡ��ǰGraphicsView��ʾ��ͼƬ
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat out;
	//�ж������˲�
	if (str=="FKFilter")
	{
		boxFilter(img, out, -1, cv::Size(5, 5));
	}
	else if(str=="JZFilter")
	{
		blur(img, out, cv::Size(7, 7));
	}
	else if(str=="GSFilter")
	{
		GaussianBlur(img, out, cv::Size(3, 3), 0, 0);
	}
	else {
		QMessageBox msgBox;
		msgBox.setWindowTitle(QStringLiteral("����"));
		msgBox.setInformativeText(QStringLiteral("�˲����ִ���"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//��������ͼƬ��������ΪcurrentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

//��̬ѧ
void MainWindows::imgDilate() {
	commonOperation("dilate");
}
void MainWindows::imgErode() {
	commonOperation("erode");
}
void MainWindows::imgOpenOperation() {
	commonOperation("open");
}
void MainWindows::imgCloseOperation() {
	commonOperation("close");
}
void MainWindows::commonOperation(QString str) {
	//�ȶ�ȡ��ǰGraphicsView��ʾ��ͼƬ
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));  //��2������Ϊ�ں˳ߴ磬��3����������ʡ���ˣ�Ĭ�ϱ�ʾê��λ������
	cv::Mat out;
	//�ж������˲�
	if (str == "dilate")
	{
		//�������Ͳ���  
		dilate(img, out, element);
	}
	else if (str == "erode")
	{
		//���и�ʴ����  
		erode(img, out, element);
	}
	else if (str == "open")
	{
		morphologyEx(img, out, cv::MORPH_OPEN, element);
	}
	else if (str=="close")
	{
		morphologyEx(img, out, cv::MORPH_CLOSE, element);
	}
	else {
		QMessageBox msgBox;
		msgBox.setWindowTitle(QStringLiteral("����"));
		msgBox.setInformativeText(QStringLiteral("��̬ѧ���ִ���"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//��������ͼƬ��������ΪcurrentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

//�̶���ֵ��
void MainWindows::imgThreshold_1() {
	//�ȶ�ȡ��ǰGraphicsView��ʾ��ͼƬ
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	//תΪ�Ҷ�ͼ
	cv::Mat srcGray;
	cv::cvtColor(img, srcGray, CV_RGB2GRAY);
	//��ʼ��threshold����Ҫ�õĸ������
	int thresh = 130;	//��ֵ���̶�ֵ���������������ǹ̶���ֵ��

	cv::Mat out;	//�ȶ���ö�ֵ��ͼ
	int threshType = 0;
	//Ԥ�����ֵ
	const int maxVal = 255;
	//�̶���ֵ������
	cv::threshold(srcGray, out, thresh, maxVal, threshType);

	//��������ͼƬ��������ΪcurrentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}
//����Ӧ��ֵ��
void MainWindows::imgThreshold_2() {
	//�ȶ�ȡ��ǰGraphicsView��ʾ��ͼƬ
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	//תΪ�Ҷ�ͼ
	cv::Mat srcGray;
	cv::cvtColor(img, srcGray, CV_RGB2GRAY);

	//��ʼ��adaptiveThreshold����Ҫ�õĸ������
	cv::Mat out;			//�ȶ���ö�ֵ��ͼ
	int blockSize = 5;		//��ʾ������С����������������ֵ��һ��Ϊ3��5��7......
	int constValue = 10;	//�̳���д��10��ûдΪëѡ10
	const int maxVal = 255;	//Ԥ��Ҷ����ֵ
	int adaptiveMethod = 0;	//����Ӧ��ֵ�㷨,0��һ�֣�1����һ��
	int thresholdType = 1;	//��ֵ���ͣ�0�Ƕ�������ֵ������������ֵ��Ϊ255��1�Ƿ���������ֵ������������ֵ��Ϊ0
	//ͼ������Ӧ��ֵ����
	adaptiveThreshold(srcGray, out, maxVal, adaptiveMethod, thresholdType, blockSize, constValue);

	//��������ͼƬ��������ΪcurrentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

//��Ե���
void MainWindows::imgEdgeDetect_1(){
	commonEdgeDetect("Canny");
}
void MainWindows::imgEdgeDetect_2() {
	commonEdgeDetect("Sobel");
}
void MainWindows::imgEdgeDetect_3() {
	commonEdgeDetect("Laplace");
}

void MainWindows::commonEdgeDetect(QString str) {
	//�ȶ�ȡ��ǰGraphicsView��ʾ��ͼƬ
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat out;

	if (str == "Canny") {
		//Canny
		cv::Canny(img, out, 100, 250);
	}
	else if(str=="Sobel")
	{
		//Sobel
		//��0������ grad_x �� grad_y ����  
		cv::Mat grad_x, grad_y;
		cv::Mat abs_grad_x, abs_grad_y;
		//��3���� X�����ݶ�  
		Sobel(img, grad_x, CV_16S, 1, 0, 3, 1, 1, cv::BORDER_DEFAULT);
		convertScaleAbs(grad_x, abs_grad_x);
		//��4����Y�����ݶ�  
		Sobel(img, grad_y, CV_16S, 0, 1, 3, 1, 1, cv::BORDER_DEFAULT);
		convertScaleAbs(grad_y, abs_grad_y);
		//��5���ϲ��ݶ�(����)  
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, out);

	}
	else if (str=="Laplace") 
	{
		cv::Mat dst;
		Laplacian(img, dst, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT);
		convertScaleAbs(dst, out);	//����ֵ
	}
	else {
		QMessageBox msgBox;
		msgBox.setWindowTitle(QStringLiteral("����"));
		msgBox.setInformativeText(QStringLiteral("��Ե�����ִ���"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//��������ͼƬ��������ΪcurrentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

/************************************************************************/
/* �м��ѶȲ������                                                      */
/************************************************************************/
void MainWindows::GSFilter_msg() {
	QDialog *gsDialog = new QDialog();
	gsDialog->resize(300, 150);	//���ô��ڴ�С�����ҿ�������϶�
	gsDialog->setAttribute(Qt::WA_DeleteOnClose);	//��ֹ�ڴ�й¶������ dialog ������ΪWA_DeleteOnClose����ô���Ի���ر�ʱ���������٣����ܻ�öԻ������ݣ���������������
	gsDialog->setWindowTitle(QStringLiteral("��˹�˲�"));
	QLabel *label = new QLabel(gsDialog);
	label->setText("Size:");
	label->setFrameShape(QFrame::Box);	//���ñ�ǩ�߽���ʽ
	QSpinBox *spinBox = new QSpinBox(gsDialog);
	spinBox->setRange(1, 15);
	spinBox->setValue(3);
	QPushButton *pushButton = new QPushButton(gsDialog);
	pushButton->setText(QStringLiteral("ȷ��"));
	QGridLayout *layout = new QGridLayout(gsDialog);
	layout->addWidget(label,0,0,1,1);	//�����ĸ����ǣ���0�У���0�У�ռ1�У�ռ1�У�
	layout->addWidget(spinBox,0,1,1,1);
	layout->addWidget(pushButton,2,1,1,1);
	gsDialog->setLayout(layout);

	m_iGSFilter = spinBox->value();	//�Ȼ��Ĭ��ֵ
	connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int value)
	{
		//qDebug() << "Value : " << value;
		m_iGSFilter = value;	//���������������ʵʱ����m_iGSFilter
	});
	connect(pushButton, &QPushButton::clicked, this, &MainWindows::GSFilter_parameter);
	connect(pushButton, &QPushButton::clicked, gsDialog, &QDialog::close);
	gsDialog->show();
}


void MainWindows::GSFilter_parameter() {
	if (m_iGSFilter!=1&& m_iGSFilter!=3&&m_iGSFilter!=7&&m_iGSFilter != 15)
	{
		QMessageBox msgBox;	//QMessageBoxϵͳǿ������������Ӧ���ڵĴ�С�����ܶ������ô�С��������д�乹�캯��
		msgBox.setWindowTitle(QStringLiteral("֪ͨ"));
		msgBox.setInformativeText(QStringLiteral("Size��������Ϊ1��3��7��15"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	//�ȶ�ȡ��ǰGraphicsView��ʾ��ͼƬ
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat out;
	//qDebug() << "GS Size:"<< m_iGSFilter;
	GaussianBlur(img, out, cv::Size(m_iGSFilter, m_iGSFilter), 0, 0);

	//��������ͼƬ��������ΪcurrentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();

}