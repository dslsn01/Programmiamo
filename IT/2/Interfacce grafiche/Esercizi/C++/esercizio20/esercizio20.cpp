/* file esercizio20.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include <QComboBox>
#include "esercizio20.h"

Esercizio20::Esercizio20(QWidget *parent) : QWidget(parent)
{
	QComboBox *color = new QComboBox(this);
	color->addItem("default");
	color->addItem("rosso");
	color->addItem("verde");
	color->addItem("blu");

	connect(color, SIGNAL(currentIndexChanged(QString)), this, SLOT(onSelectItem(QString)));

	QVBoxLayout *layout = new QVBoxLayout(this);

	layout->addWidget(color);
	this->setLayout(layout);

	this->resize(200, 50);
	this->setWindowTitle("Scegli il colore");
	this->show();
}

void Esercizio20::onSelectItem(QString s) {
	if (s == "default") {
		this->setStyleSheet("");
	}
	if (s == "rosso") {
		this->setStyleSheet("background-color: red;");
	}
	if (s == "verde") {
		this->setStyleSheet("background-color: green;");
	}
	if (s == "blu") {
		this->setStyleSheet("background-color: blue;");
	}
}

