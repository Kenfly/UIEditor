#include <QtWidgets/QApplication>
#include "View/UIEditor.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	UIEditor* pWindow = new UIEditor();
	pWindow->show();

	return a.exec();
}
