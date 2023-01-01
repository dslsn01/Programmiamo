/* file esercizio23.cpp */

#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QPixmap pm(100, 100);
	pm.fill(QColor("transparent"));
	QPainter p(&pm);

	p.setRenderHint(QPainter::Antialiasing);
	p.drawEllipse(10, 10, 80, 80);

	QLabel label;
	label.setPixmap(pm);
	label.show();

	return application.exec();
}

