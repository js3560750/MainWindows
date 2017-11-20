#include "MainWindows.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp> 
//using namespace cv;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindows w;
	//w.show();

	return a.exec();
}
