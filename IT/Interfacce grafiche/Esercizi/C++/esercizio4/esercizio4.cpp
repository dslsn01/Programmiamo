/* file esercizio4.cpp */

#include <QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QMainWindow frame;
	frame.resize(150, 100);
	application.setWindowIcon(QIcon("img/icon.gif"));
	frame.setWindowTitle("Icona");
	frame.show();

	return application.exec();
}

