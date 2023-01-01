/* file esercizio6.cpp */

#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QLabel label("La tua stringa");
	label.show();

	return application.exec();
}

