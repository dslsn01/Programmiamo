/* file esercizio13.cpp */

#include <QApplication>
#include "esercizio13.h"

Esercizio13::Esercizio13(QWidget *parent) : QWidget(parent)
{
	button = new QPushButton("Chiudi", this);
	connect(button, SIGNAL(clicked()), this, SLOT(close()));
	button->show();
	this->show();
}

void Esercizio13::close()
{
	QApplication::quit();
}

