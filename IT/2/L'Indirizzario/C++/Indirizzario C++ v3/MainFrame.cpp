/* file MainFrame.cpp */

#include <QApplication>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "MainFrame.h"
#include "Contact.h"
#include "NContact.h"

namespace ind = programmiamo::ind;

ind::MainFrame::MainFrame(QWidget *parent) : QMainWindow(parent) 
{
	/* crea il Notebook */

	tabs = new QTabWidget(this);

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("addrb.sqlite");
	db.open();

	/* se non esiste, crea la tabella dei contatti */

	QSqlQuery query("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY, name VARCHAR, surname VARCHAR, addr VARCHAR, pnum VARCHAR, email VARCHAR, CHECK(LENGTH(pnum <= 15)))");

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

/* gestisce il click sul menu "Cancella", cancellando la linguetta corrente */ 

void ind::MainFrame::remove()
{
	int index = tabs->currentIndex();

	if (index == -1) {
		return;
	}

	QWidget* widget = tabs->currentWidget();
	Contact* tab = dynamic_cast<Contact*>(widget);

	if (tab) {
		QString name = tab->name->text();
		QString surname = tab->surname->text();

		QSqlQuery pStmt;
		pStmt.prepare("DELETE FROM contacts WHERE name = :name AND surname = :surname");
		pStmt.bindValue(":name", name);
		pStmt.bindValue(":surname", surname);
		pStmt.exec();
	}

	tabs->removeTab(index);
}

/* gestisce il click sul menu "Esci", chiudendo l'applicazione */ 

void ind::MainFrame::exit()
{
	QApplication::quit();
}

/* crea le linguette dei contatti nel Notebook */

void ind::MainFrame::updateUI()
{
	tabs->clear();

	QSqlQuery query("SELECT name, surname, addr, pnum, email FROM contacts");

	/* recupera i dati (nome, cognome, ...) dal database */

	while (query.next()) {
		QString name = query.value(0).toString();
		QString surname = query.value(1).toString();
		QString addr = query.value(2).toString();
		QString pnum = query.value(3).toString();
		QString email = query.value(4).toString();

		QString pageName = name + " " + surname;

		Contact *contact = new Contact(tabs, name, surname, addr, pnum, email);
		tabs->addTab(contact, pageName);
	}
}

