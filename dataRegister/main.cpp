#include "dataregister.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dataRegister w;

	w.show();
	return a.exec();
}
