/* file esercizio25.cpp */

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
	p.setPen(QPen(Qt::red));
	p.setBrush(QBrush(Qt::red));
	p.drawEllipse(10, 10, 80, 80);
	p.setPen(QPen(Qt::green));
	p.setBrush(QBrush(Qt::green));
	p.drawEllipse(20, 20, 60, 60);
	p.setPen(QPen(Qt::blue));
	p.setBrush(QBrush(Qt::blue));
	p.drawEllipse(30, 30, 40, 40);

	QLabel label;
	label.setPixmap(pm);
	label.show();

	return application.exec();
}

