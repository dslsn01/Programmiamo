/* file esercizio27.cpp */

#include <QApplication>
#include <QPainter>
#include <cmath>
#include "esercizio27.h"

Esercizio27::Esercizio27(QWidget *parent) : QWidget(parent)
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

void Esercizio27::mousePressEvent(QMouseEvent* event) {
	QPoint cursor = event->pos();
	this->x0 = cursor.x();
	this->y0 = cursor.y();
}

void Esercizio27::mouseReleaseEvent(QMouseEvent* event) {
	QPoint cursor = event->pos();
	int x1 = cursor.x();
	int y1 = cursor.y();
	// raggio della circonferenza
	double r = sqrt(pow((double) x1 - this->x0, 2.0) + pow((double) y1 - this->y0, 2.0));

	QPainter p(&canvas);
	p.setRenderHint(QPainter::Antialiasing);
	p.drawEllipse(QPoint(x0, y0), r, r);
	update();
}

void Esercizio27::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	QRect rect = event->rect();
	painter.drawImage(rect, canvas, rect);
}

