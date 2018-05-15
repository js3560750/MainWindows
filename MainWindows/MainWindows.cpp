#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	
	//赋初值，不能在头文件中赋初值，头文件中只是声明
	m_iGSFilter = 0;	//中级难度高斯滤波所用参数
	sceneWindows = nullptr;	//不初始化的话指针值的初始值是乱值
	dialog = nullptr;
	hardChooseWindows = NULL;	
	//NULL无类型，nullptr有类型,类型是nullptr_t，我们应该使用nullptr，这给我们编译器实现nullptr的时候带来了更多细节的考虑，当然也给了使用者更多的保障，
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

而引入了nullptr，这个问题就得到了真正解决，会很顺利的调到void f(void*)这个版本。
	*/
	levelEasyWindows = nullptr;
	levelMiddleWindows = nullptr;



	sceneWindows = new SceneWindows;
	sceneWindows->show();


	//场景选择
	connect(sceneWindows, &SceneWindows::sendSceneSignal1, this, &MainWindows::login1);
	connect(sceneWindows, &SceneWindows::sendSceneSignal2, this, &MainWindows::login2);
	connect(sceneWindows, &SceneWindows::sendSceneSignal3, this, &MainWindows::login3);

	//各场景公用参数初始化
	initCamera();
	initLens();
	initLS();
	initLD();


	//查看检测需求
	connect(ui.buttonCheckRequirement, &QPushButton::clicked, this, &MainWindows::checkRequirement);

	//确定精度
	connect(ui.buttonAccuracy, &QPushButton::clicked, this, &MainWindows::checkAccuracy);

	//上一步（返回场景选择）
	connect(ui.buttonLast, &QPushButton::clicked, this, &MainWindows::toLast);
	//下一步
	connect(ui.buttonNext, &QPushButton::clicked, this, &MainWindows::toNext);
	ui.buttonNext->setEnabled(false);	//只有精度通过后才能点击下一步
	

	
}

/************************************************************************/
/* 场景选择                                                          */
/************************************************************************/
void MainWindows::login1() {
	m_iScene = 1;
	initGraphicsView();	//选择场景之后再初始化图片
	this->show();
	sceneWindows->close();
}

void MainWindows::login2() {
	m_iScene = 2;
	initGraphicsView();//选择场景之后再初始化图片
	this->show();
	sceneWindows->close();
}

void MainWindows::login3() {
	m_iScene = 3;
	initGraphicsView();//选择场景之后再初始化图片
	this->show();
	sceneWindows->close();
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
	delete config;
	config = NULL;

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

	m_iCamera = index;	//标记用户选择几号相机

	delete config;
	config = NULL;
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

	m_iLens = index;	//标记用户选择几号镜头

	delete config;
	config = NULL;
}

//光源选择初始化
void MainWindows::initLS(){
	ui.comboBoxLightSource->addItem(QStringLiteral("请选择"));
	ui.comboBoxLightSource->addItem(QStringLiteral("光源1:MSU-10-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("光源2:MSU-30-SW/BL/GR"));
	ui.comboBoxLightSource->addItem(QStringLiteral("光源3:MSU-30×20-SW/BL/GR"));
	connect(ui.comboBoxLightSource,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLS);
}
void MainWindows::boxChangeLS(int index){
	//读取配置文件
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	QString chiCun = QStringLiteral("尺寸： ") + config->value("/LightSource" + QString::number(index) + "/chiCun").toString() + QString("<br><br>");
	QString color = QStringLiteral("颜色： ") + config->value("/LightSource" + QString::number(index) + "/color").toString() + QString("<br><br>");
	QString str = chiCun + color;
	ui.labelLightSourceDetail->setText(str);

	m_iLS = index;	//标记用户选择几号光源

	delete config;
	config = NULL;
}

//光源距离选择的初始化
void MainWindows::initLD() {
	ui.comboBoxLightDistance->addItem(QStringLiteral("请选择"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("远"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("中"));
	ui.comboBoxLightDistance->addItem(QStringLiteral("近"));
	connect(ui.comboBoxLightDistance,
		static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this,
		&MainWindows::boxChangeLD);
}
void MainWindows::boxChangeLD(int index) {
	qDebug() << index;
	QString str = QString::number(index);	//QT中int和String的转型
	QMessageBox msgBox;
	msgBox.setInformativeText(str);
	msgBox.exec();

	m_iLD = index;	//标记用户选择几号光源距离
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

	//保存GraphicsView当前图片为currentImage.jpg
	QImage currentImage;
	currentImage.load(str);	
	currentImage.save("./images/currentImage.jpg", "JPG");




	delete config;
	config = NULL;


	
}

//上一步（返回场景选择）
void MainWindows::toLast() {
	this->close();
	//如果进入了初中高级实验界面，返回场景选择时就要关闭这些窗口
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

//下一步
void MainWindows::toNext() {

	bool flag = checkAccuracy();	//查看用户输入的精度合格否
	if (flag==false)
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("输入的精度不符合实验要求"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		ui.buttonNext->setEnabled(false);
	}
	else
	{
		//检测精度通过后选择实验难度
		hardChooseWindows = new HardChooseWindows();
		hardChooseWindows->setWindowTitle(QStringLiteral("难度选择"));
		hardChooseWindows->setWindowModality(Qt::ApplicationModal);	//设置QWidget窗口为模糊窗口，该QWidget必须没有传入父类
		hardChooseWindows->show();

		//新建对象之后再连接槽函数，选择好了难度
		connect(hardChooseWindows, &HardChooseWindows::okSignal, this, &MainWindows::levelOK);
	}

	

}

/************************************************************************/
/* 确定精度                                                              */
/************************************************************************/
bool MainWindows::checkAccuracy() {
	
	double inputAccuracy = ui.spinBoxAccuracy->value();	//获取用户输入的精度
	if (inputAccuracy==NULL&&inputAccuracy==0)
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("请输入精度"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return false;
	}
	qDebug() << inputAccuracy;

	//读取配置文件，获得不同场景所需的精度
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	double sceneAccuracy = config->value("/SceneAccuracy" + QString::number(m_iScene) + "/accuracy").toDouble();
	
	delete config;
	config = NULL;

	//如果用户输入精度小于场景所需精度，则返回true
	if (inputAccuracy<=sceneAccuracy)
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("输入精度符合要求"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();

		ui.buttonNext->setEnabled(true);	//只有精度通过后才能点击下一步
		return true;
	}
	else
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("输入的精度不符合实验要求"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return false;
	}

}

/************************************************************************/
/* 选择好了难度                                                          */
/************************************************************************/
void MainWindows::levelOK() {
	
	int level = hardChooseWindows->getLevel();
	
	//Level=-2 初级难度
	//Level=-3 中级难度
	//Level=-4 高级难度
	
	if (level==-2)	//简单难度
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("您选择了初级难度"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		//ui.buttonLast->setHidden(true);	//隐藏上一步按钮
		ui.buttonNext->setHidden(true);	//隐藏下一步按钮

		//弹出初级实验界面，并覆盖主窗口的相机、镜头等的选择界面
		levelEasyWindows = new LevelEasy(this);
		levelEasyWindows->setAutoFillBackground(true);	
		levelEasyWindows->setGeometry(740, 15, 270, 700);
		levelEasyWindows->show();
		
		//恢复为原图
		connect(levelEasyWindows, &LevelEasy::revertSignal, this, &MainWindows::imgRevert);
		//滤波
		connect(levelEasyWindows, &LevelEasy::fkFilterSignal, this, &MainWindows::FKFilter);
		connect(levelEasyWindows, &LevelEasy::jzFilterSignal, this, &MainWindows::JZFilter);
		connect(levelEasyWindows, &LevelEasy::gsFilterSignal, this, &MainWindows::GSFilter);
		//形态学
		connect(levelEasyWindows, &LevelEasy::dilateSignal, this, &MainWindows::imgDilate);
		connect(levelEasyWindows, &LevelEasy::erodeSignal, this, &MainWindows::imgErode);
		connect(levelEasyWindows, &LevelEasy::openOperationSignal, this, &MainWindows::imgOpenOperation);
		connect(levelEasyWindows, &LevelEasy::closeOperationSignal, this, &MainWindows::imgCloseOperation);
		//二值化
		connect(levelEasyWindows, &LevelEasy::thresholdSignal_1, this, &MainWindows::imgThreshold_1);
		connect(levelEasyWindows, &LevelEasy::thresholdSignal_2, this, &MainWindows::imgThreshold_2);
		//边缘检测
		connect(levelEasyWindows, &LevelEasy::edgeDetectSignal_1, this, &MainWindows::imgEdgeDetect_1);
		connect(levelEasyWindows, &LevelEasy::edgeDetectSignal_2, this, &MainWindows::imgEdgeDetect_2);
		connect(levelEasyWindows, &LevelEasy::edgeDetectSignal_3, this, &MainWindows::imgEdgeDetect_3);
	}
	else if (level==-3)	//中级难度
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("您选择了中级难度"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		//ui.buttonLast->setHidden(true);	//隐藏上一步按钮
		ui.buttonNext->setHidden(true);	//隐藏下一步按钮

		//弹出初级实验界面，并覆盖主窗口的相机、镜头等的选择界面
		levelMiddleWindows = new LevelMiddle(this);
		levelMiddleWindows->setAutoFillBackground(true);
		levelMiddleWindows->setGeometry(740, 15, 270, 700);
		levelMiddleWindows->show();

		//恢复为原图
		connect(levelMiddleWindows, &LevelMiddle::revertSignal, this, &MainWindows::imgRevert);
		//滤波
		connect(levelMiddleWindows, &LevelMiddle::gsFilterSignal, this, &MainWindows::GSFilter_msg);
	}

}

/************************************************************************/
/* 简单难度操作面板                                                      */
/************************************************************************/
//恢复为原图
void MainWindows::imgRevert() {
	initGraphicsView();
}

//滤波
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
	//先读取当前GraphicsView显示的图片
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat out;
	//判断哪种滤波
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
		msgBox.setWindowTitle(QStringLiteral("错误"));
		msgBox.setInformativeText(QStringLiteral("滤波出现错误"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//将处理后的图片继续保存为currentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

//形态学
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
	//先读取当前GraphicsView显示的图片
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));  //第2个参数为内核尺寸，第3个参数这里省略了，默认表示锚点位于中心
	cv::Mat out;
	//判断哪种滤波
	if (str == "dilate")
	{
		//进行膨胀操作  
		dilate(img, out, element);
	}
	else if (str == "erode")
	{
		//进行腐蚀操作  
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
		msgBox.setWindowTitle(QStringLiteral("错误"));
		msgBox.setInformativeText(QStringLiteral("形态学出现错误"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//将处理后的图片继续保存为currentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

//固定二值化
void MainWindows::imgThreshold_1() {
	//先读取当前GraphicsView显示的图片
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	//转为灰度图
	cv::Mat srcGray;
	cv::cvtColor(img, srcGray, CV_RGB2GRAY);
	//初始化threshold函数要用的各类参数
	int thresh = 130;	//阈值，固定值！！！！！所以是固定二值化

	cv::Mat out;	//先定义好二值化图
	int threshType = 0;
	//预设最大值
	const int maxVal = 255;
	//固定阈值化操作
	cv::threshold(srcGray, out, thresh, maxVal, threshType);

	//将处理后的图片继续保存为currentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}
//自适应二值化
void MainWindows::imgThreshold_2() {
	//先读取当前GraphicsView显示的图片
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	//转为灰度图
	cv::Mat srcGray;
	cv::cvtColor(img, srcGray, CV_RGB2GRAY);

	//初始化adaptiveThreshold函数要用的各类参数
	cv::Mat out;			//先定义好二值化图
	int blockSize = 5;		//表示领域块大小，用来计算区域阈值，一般为3、5、7......
	int constValue = 10;	//教程中写的10，没写为毛选10
	const int maxVal = 255;	//预设灰度最大值
	int adaptiveMethod = 0;	//自适应阈值算法,0是一种，1是另一种
	int thresholdType = 1;	//阈值类型，0是二进制阈值化，即大于阈值的为255。1是反二进制阈值化，即大于阈值的为0
	//图像自适应阈值操作
	adaptiveThreshold(srcGray, out, maxVal, adaptiveMethod, thresholdType, blockSize, constValue);

	//将处理后的图片继续保存为currentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

//边缘检测
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
	//先读取当前GraphicsView显示的图片
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat out;

	if (str == "Canny") {
		//Canny
		cv::Canny(img, out, 100, 250);
	}
	else if(str=="Sobel")
	{
		//Sobel
		//【0】创建 grad_x 和 grad_y 矩阵  
		cv::Mat grad_x, grad_y;
		cv::Mat abs_grad_x, abs_grad_y;
		//【3】求 X方向梯度  
		Sobel(img, grad_x, CV_16S, 1, 0, 3, 1, 1, cv::BORDER_DEFAULT);
		convertScaleAbs(grad_x, abs_grad_x);
		//【4】求Y方向梯度  
		Sobel(img, grad_y, CV_16S, 0, 1, 3, 1, 1, cv::BORDER_DEFAULT);
		convertScaleAbs(grad_y, abs_grad_y);
		//【5】合并梯度(近似)  
		addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, out);

	}
	else if (str=="Laplace") 
	{
		cv::Mat dst;
		Laplacian(img, dst, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT);
		convertScaleAbs(dst, out);	//绝对值
	}
	else {
		QMessageBox msgBox;
		msgBox.setWindowTitle(QStringLiteral("错误"));
		msgBox.setInformativeText(QStringLiteral("边缘检测出现错误"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}

	//将处理后的图片继续保存为currentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}

/************************************************************************/
/* 中级难度操作面板                                                      */
/************************************************************************/
void MainWindows::GSFilter_msg() {
	QDialog *gsDialog = new QDialog();
	gsDialog->resize(300, 150);	//设置窗口大小，并且可用鼠标拖动
	gsDialog->setAttribute(Qt::WA_DeleteOnClose);	//防止内存泄露，设置 dialog 的属性为WA_DeleteOnClose，那么当对话框关闭时，对象被销毁，不能获得对话框数据！！！！！！！！
	gsDialog->setWindowTitle(QStringLiteral("高斯滤波"));
	QLabel *label = new QLabel(gsDialog);
	label->setText("Size:");
	label->setFrameShape(QFrame::Box);	//设置标签边界样式
	QSpinBox *spinBox = new QSpinBox(gsDialog);
	spinBox->setRange(1, 15);
	spinBox->setValue(3);
	QPushButton *pushButton = new QPushButton(gsDialog);
	pushButton->setText(QStringLiteral("确定"));
	QGridLayout *layout = new QGridLayout(gsDialog);
	layout->addWidget(label,0,0,1,1);	//后面四个数是（第0行，第0列，占1行，占1列）
	layout->addWidget(spinBox,0,1,1,1);
	layout->addWidget(pushButton,2,1,1,1);
	gsDialog->setLayout(layout);

	m_iGSFilter = spinBox->value();	//先获得默认值
	connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int value)
	{
		//qDebug() << "Value : " << value;
		m_iGSFilter = value;	//如果调整参数，则实时赋给m_iGSFilter
	});
	connect(pushButton, &QPushButton::clicked, this, &MainWindows::GSFilter_parameter);
	connect(pushButton, &QPushButton::clicked, gsDialog, &QDialog::close);
	gsDialog->show();
}


void MainWindows::GSFilter_parameter() {
	if (m_iGSFilter!=1&& m_iGSFilter!=3&&m_iGSFilter!=7&&m_iGSFilter != 15)
	{
		QMessageBox msgBox;	//QMessageBox系统强制限制了自适应窗口的大小，不能额外设置大小，除非重写其构造函数
		msgBox.setWindowTitle(QStringLiteral("通知"));
		msgBox.setInformativeText(QStringLiteral("Size参数必须为1、3、7、15"));
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
		return;
	}
	//先读取当前GraphicsView显示的图片
	cv::Mat img = cv::imread("./images/currentImage.jpg");
	cv::Mat out;
	//qDebug() << "GS Size:"<< m_iGSFilter;
	GaussianBlur(img, out, cv::Size(m_iGSFilter, m_iGSFilter), 0, 0);

	//将处理后的图片继续保存为currentImage.jpg
	cv::imwrite("./images/currentImage.jpg", out);
	QString url = "./images/currentImage.jpg";
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap(url));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();

}