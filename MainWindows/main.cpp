#include "MainWindows.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindows w;
	//w.show();

	//��ȡ�����ļ�
	QSettings *config = new QSettings("./Profile/initMainWindows.ini", QSettings::IniFormat);
	config->setIniCodec("UTF8");	//�����������
	QString word = QString::fromUtf8(config->value("/Test/word").toByteArray());	//����д�������ֳ��˸���û����
	QString name = config->value("/Test/name").toString();	//����д��
	qDebug() << word;
	qDebug() << name;
	delete config;
	config = NULL;
	return a.exec();
}
