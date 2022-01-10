/* file esercizio17.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include <QMenuBar>
#include "esercizio17.h"

Esercizio17::Esercizio17(QWidget *parent) : QMainWindow(parent)
{
	QMenu *fileMenu = menuBar()->addMenu("&File");

	QAction *closeAction = new QAction("Esci", this);
	fileMenu->addAction(closeAction);

	connect(closeAction, SIGNAL(triggered()), this, SLOT(closeHandler()));

	text = new QTextEdit();
	button1 = new QPushButton("Testa", this);
	connect(button1, SIGNAL(clicked()), this, SLOT(btn1ClickHandler()));
	button1->show();

	button2 = new QPushButton("Croce", this);
	connect(button2, SIGNAL(clicked()), this, SLOT(btn2ClickHandler()));
	button2->show();

	QWidget *widget = new QWidget(this);

	QVBoxLayout *layout = new QVBoxLayout(widget);
	layout->addWidget(text);
	layout->addWidget(button1);
	layout->addWidget(button2);
	widget->setLayout(layout);

	this->setCentralWidget(widget);

	this->resize(280, 250);
	this->setWindowTitle("Testa o croce?");
	this->show();
}

void Esercizio17::btn1ClickHandler()
{
	text->append("Testa");
}

void Esercizio17::btn2ClickHandler()
{
	text->append("Croce");
}

void Esercizio17::closeHandler()
{
	QApplication::quit();
}

