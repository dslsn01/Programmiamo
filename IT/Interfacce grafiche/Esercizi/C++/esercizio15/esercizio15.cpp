/* file esercizio15.cpp */

#include <QApplication>
#include <QMenuBar>
#include "esercizio15.h"

Esercizio15::Esercizio15(QWidget *parent) : QMainWindow(parent)
{
	QMenu *fileMenu = menuBar()->addMenu("&File");

	QAction *closeAction = new QAction("Esci", this);
	fileMenu->addAction(closeAction);

	connect(closeAction, SIGNAL(triggered()), this, SLOT(closeHandler()));

	this->resize(100, 50);
	this->show();
}

void Esercizio15::closeHandler()
{
	QApplication::quit();
}

