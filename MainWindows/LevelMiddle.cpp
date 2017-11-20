#include "LevelMiddle.h"

LevelMiddle::LevelMiddle(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//»Ö¸´ÎªÔ­Í¼
	connect(ui.buttonRevert, &QPushButton::clicked, this, &LevelMiddle::sendRevert);

	//ÂË²¨
	connect(ui.buttonGSFilter, &QPushButton::clicked, this, &LevelMiddle::sendGSFilter);
}

LevelMiddle::~LevelMiddle()
{
}

void LevelMiddle::sendRevert() {
	emit revertSignal();
}

void LevelMiddle::sendGSFilter() {
	emit gsFilterSignal();
}