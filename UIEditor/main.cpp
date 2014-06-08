#include "uieditor.h"
#include <QtWidgets/QApplication>
#include "cocos2d.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UIEditor w;
	w.show();
	return a.exec();
}
