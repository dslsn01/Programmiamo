/* file esercizio5.cpp */

#include <QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QMainWindow frame;
	frame.resize(150, 100);
	frame.setWindowTitle("Titolo");
	frame.setStyleSheet("background-color: red;");
	frame.show();

	return application.exec();
}

