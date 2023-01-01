/* file main.cpp */

#include <QApplication>
#include "EventHandling.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	EventHandling e;

	return app.exec();
}

