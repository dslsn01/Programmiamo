/* file esercizio12.cpp */

#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char* argv[]) 
{
	QApplication application(argc, argv);

	QWidget *window = new QWidget();

	QPushButton *button = new QPushButton("Click", window);

	button->show();
	window->show();

	return application.exec();
}

