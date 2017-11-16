#include "MainWindows.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindows w;
	//w.show();

	//读取配置文件
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//解决中文乱码
	QString word = QString::fromUtf8(config->value("/Test/word").toByteArray());	//两种写法，这种除了复杂没卵用
	QString name = config->value("/Test/name").toString();	//两种写法
	qDebug() << word;
	qDebug() << name;
	delete config;
	config = NULL;
	return a.exec();
}
