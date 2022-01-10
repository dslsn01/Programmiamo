/* file esercizio14.cpp */

#include <QApplication>
#include <QMessageBox>
#include "esercizio14.h"

Esercizio14::Esercizio14(QWidget *parent) : QWidget(parent)
{
	button = new QPushButton("Aiuto", this);
	connect(button, SIGNAL(clicked()), this, SLOT(showPopUp()));
	button->show();
	this->show();
}

void Esercizio14::showPopUp()
{
	QMessageBox::information(NULL, "Alert", "Hai chiesto aiuto!");
}

