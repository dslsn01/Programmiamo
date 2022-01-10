/* file esercizio10.cpp */

#include <QApplication>
#include <QMainWindow>
#include <QPixmap>
#include <QPalette>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QMainWindow frame;

	QPixmap img("img/image.gif");
	QPalette palette;
	palette.setBrush(QPalette::Background, img);
	frame.setPalette(palette);
	frame.resize(img.size());

	frame.setWindowTitle("Immagine");
	frame.show();

	return application.exec();
}

