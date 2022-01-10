/* file MainFrame.cpp */

#include <QApplication>
#include <QMenuBar>
#include <QVBoxLayout>
#include "MainFrame.h"
#include "Contact.h"
#include "NContact.h"

namespace ind = programmiamo::ind;

ind::MainFrame::MainFrame(QWidget *parent) : QMainWindow(parent) 
{
	/* crea il Notebook */

	tabs = new QTabWidget(this);

	updateUI();

	QMenu *fileMenu = menuBar()->addMenu("&File");

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

	this->resize(640, 480);
	this->show();
}

/* gestisce il click sul menu "Nuovo", e apre una nuova finestra per inserire un nuovo contatto */

void ind::MainFrame::save()
{
	NContact* window = new NContact(this);
	window->exec();
}

/* gestisce il click sul menu "Cancella": per ora non fa nulla */ 

void ind::MainFrame::remove() {}

/* gestisce il click sul menu "Esci", chiudendo l'applicazione */ 

void ind::MainFrame::exit()
{
	QApplication::quit();
}

/* crea le linguette dei contatti nel Notebook */

void ind::MainFrame::updateUI()
{
	for (int counter = 1; counter < 4; counter++) {
		QString pageName = "Pagina " + QString::number(counter);
		Contact *contact = new Contact(tabs, "Nome", "Cognome", "Indirizzo", "Telefono", "E-mail");
		tabs->addTab(contact, pageName);
	}
}

