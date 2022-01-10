/* file esercizio3.cpp */

#include <QApplication>
#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QMainWindow frame;
	frame.resize(150, 100);

	frame.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, frame.size(), application.desktop()->availableGeometry()));

	frame.setWindowTitle("Titolo");
	frame.show();

	return application.exec();
}

