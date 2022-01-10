/* file esercizio18.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QLabel>
#include "esercizio18.h"

Esercizio18::Esercizio18(QWidget *parent) : QMainWindow(parent)
{
	QMenu *fileMenu = menuBar()->addMenu("&File");

	QAction *action1 = new QAction("Testa", this);
	QAction *action2 = new QAction("Croce", this);
	QAction *closeAction = new QAction("Esci", this);

	fileMenu->addAction(action1);
	fileMenu->addAction(action2);
	fileMenu->addAction(closeAction);

	connect(action1, SIGNAL(triggered()), this, SLOT(menu1ClickHandler()));
	connect(action2, SIGNAL(triggered()), this, SLOT(menu2ClickHandler()));
	connect(closeAction, SIGNAL(triggered()), this, SLOT(closeHandler()));

	text = new QTextEdit();

	QWidget *widget = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout(widget);
	layout->addWidget(text);

	QLabel *label = new QLabel("Lancia la monetina con il menu a tendina.");
	layout->addWidget(label);

	widget->setLayout(layout);
	this->setCentralWidget(widget);

	this->resize(280, 250);
	this->setWindowTitle("Testa o croce?");
	this->show();
}

void Esercizio18::menu1ClickHandler()
{
	text->append("Testa");
}

void Esercizio18::menu2ClickHandler()
{
	text->append("Croce");
}

void Esercizio18::closeHandler()
{
	QApplication::quit();
}

