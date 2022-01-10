/* file MainFrame.cpp */

#include <QApplication>
#include <QMenuBar>
#include <QVBoxLayout>
#include "MainFrame.h"

namespace ind = programmiamo::ind;

ind::MainFrame::MainFrame(QWidget *parent) : QMainWindow(parent) 
{
	/* crea il Notebook */

	tabs = new QTabWidget(this);

	updateUI();

	QMenu *fileMenu = menuBar()->addMenu("&File");

	/* aggiunge tre sottomenu al menu "file" */

	QAction *saveAction = new QAction("Nuovo", this);
	QAction *removeAction = new QAction("Cancella", this);
	QAction *exitAction = new QAction("Esci", this);

	fileMenu->addAction(saveAction);
	fileMenu->addAction(removeAction);
	fileMenu->addAction(exitAction);

	/* associa a ogni voce del menu il relativo gestore di evento */

	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
	connect(removeAction, SIGNAL(triggered()), this, SLOT(remove()));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));

	QWidget *panel = new QWidget(this);
	this->setCentralWidget(panel);

	QVBoxLayout *box = new QVBoxLayout();
	box->setMargin(0);
	box->addWidget(tabs);
	panel->setLayout(box);

	// 600 invece di 640?
	this->resize(640, 480);
	this->show();
}

/* gestisce il click sul menu "Nuovo": per ora non fa nulla */

void ind::MainFrame::save() {}

/* gestisce il click sul menu "Cancella": per ora non fa nulla */ 

void ind::MainFrame::remove() {}

/* gestisce il click sul menu "Esci", chiudendo l'applicazione */ 

void ind::MainFrame::exit()
{
	QApplication::quit();
}

/* crea le linguette nel Notebook */

void ind::MainFrame::updateUI()
{
	for (int counter = 1; counter < 4; counter++) {
		QString pageName = "Pagina " + QString::number(counter);
		tabs->addTab(new QWidget(), pageName);
	}
}

