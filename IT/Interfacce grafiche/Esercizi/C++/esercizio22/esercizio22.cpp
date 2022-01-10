/* file esercizio22.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include "esercizio22.h"

esercizio22::esercizio22(QWidget *parent) : QWidget(parent)
{
	this->label = new QLabel("x, y: ", this);
	QVBoxLayout *layout = new QVBoxLayout(this);

	layout->addWidget(this->label);
	this->setLayout(layout);

	this->resize(200, 50);
	this->setMouseTracking(true);
	this->show();
}

void esercizio22::mouseMoveEvent(QMouseEvent* event) {
	QPoint cursor = event->pos();
	int x = cursor.x();
	int y = cursor.y();
	this->label->setText("x = " + QString::number(x) + ", y = " + QString::number(y));
}

