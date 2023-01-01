/* file esercizio1.cpp */

#include <QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QMainWindow frame;
	frame.resize(150, 100);
	frame.show();

	return application.exec();
}

