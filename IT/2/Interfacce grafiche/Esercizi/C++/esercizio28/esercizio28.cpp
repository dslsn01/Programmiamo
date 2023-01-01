/* file esercizio28.cpp */

#include <QPainter>
#include "esercizio28.h"
// #include <algorithm>

using std::random_shuffle;

Esercizio28::Esercizio28(QWidget *parent) : QWidget(parent)
{
	int w = 400;
	int h = 400;
	QImage bg(QSize(w, h), QImage::Format_ARGB32);
	bg.fill(QColor("transparent"));
	QPainter p(&bg);
	p.drawImage(QPoint(0, 0), canvas);
	canvas = bg;
	resize(w, h);
	show();
}

void Esercizio28::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		QPoint cursor = event->pos();
		double x = cursor.x();
		double y = cursor.y();
		coords.push_back(QPointF(x, y));
	}
	else if (event->button() == Qt::RightButton) {
		QPolygonF p(coords);
		random_shuffle(colors, colors+6);
		QColor c = colors[0];
		ngons.push_back(qMakePair(p, c.name()));
		coords.clear();
		update();
	}
}

void Esercizio28::paintEvent(QPaintEvent*) {
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);

	for (int i = 0; i < ngons.size(); i++) {
		QPair<QPolygonF, QString> pair = ngons[i];
		QPolygonF poly = pair.first;
		QString color = pair.second;
		p.setPen(QPen(color));
		QColor c(color);
		QBrush brush(c);
		p.setBrush(brush);
		p.drawPolygon(poly);
	}
}

