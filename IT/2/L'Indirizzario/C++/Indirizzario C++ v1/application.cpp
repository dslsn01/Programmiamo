/* file application.cpp */

#include <QApplication>
#include "MainFrame.h"

using namespace programmiamo::ind;

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	MainFrame f;

	return application.exec();
}

