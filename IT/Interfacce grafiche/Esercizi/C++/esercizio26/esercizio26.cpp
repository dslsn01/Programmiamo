/* file esercizio26.cpp */

#include <QPainter>
#include <cmath>
#include "esercizio26.h"

Esercizio26::Esercizio26(QWidget *parent) : QWidget(parent)
{
	int w = 400;
	int h = 400;
	QImage bg(QSize(w, h), QImage::Format_ARGB32);
	bg.fill(QColor("transparent"));
	QPainter p(&bg);
	p.drawImage(QPoint(0, 0), canvas);
	canvas = bg;

	for (int i = 3; i <= 12; i++) {
		addPolygon(w, h, i);
	}

	resize(w, h);
	show();
}

void Esercizio26::paintEvent(QPaintEvent*) {
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);

	for (int i = 0; i < ngons.size(); i++) {
		QPolygonF poly = ngons[i];
		p.drawPolygon(poly);
	}
}

void Esercizio26::addPolygon(int width, int height, int nVertx) {
	int r = width / 2;
	int x0 = r;
	int y0 = height / 2;
	QVector<QPointF> coords;
	double thetaI = 2 * M_PI / nVertx;
	double theta = (nVertx % 2) == 0 ? thetaI : -M_PI/2;
	for (int i = 0; i < nVertx; i++) {
		double x = x0 + r * cos(theta);
		double y = y0 + r * sin(theta);
		coords.push_back(QPointF(x, y));
		theta += thetaI;
	}

	QPolygonF p(coords);
	ngons.push_back(p);
}

