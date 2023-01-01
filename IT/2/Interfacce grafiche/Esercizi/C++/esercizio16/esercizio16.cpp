/* file esercizio16.cpp */

#include <QVBoxLayout>
#include "esercizio16.h"

Esercizio16::Esercizio16(QWidget *parent) : QWidget(parent)
{
	text = new QTextEdit();
	button1 = new QPushButton("Testa", this);
	connect(button1, SIGNAL(clicked()), this, SLOT(btn1ClickHandler()));
	button1->show();

	button2 = new QPushButton("Croce", this);
	connect(button2, SIGNAL(clicked()), this, SLOT(btn2ClickHandler()));
	button2->show();

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(text);
	layout->addWidget(button1);
	layout->addWidget(button2);

	this->setLayout(layout);
	this->resize(280, 250);
	this->setWindowTitle("Testa o croce?");
	this->show();
}

void Esercizio16::btn1ClickHandler()
{
	text->append("Testa");
}

void Esercizio16::btn2ClickHandler()
{
	text->append("Croce");
}

