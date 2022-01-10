/* file esercizio7.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QWidget *window = new QWidget();

	QLabel *label1 = new QLabel("Un'etichetta", window);
	QLabel *label2 = new QLabel("Un'altra etichetta", window);

	QVBoxLayout *layout = new QVBoxLayout(window);
	layout->addWidget(label1);
	layout->addWidget(label2);

	window->setLayout(layout);
	window->show();

	return application.exec();
}

