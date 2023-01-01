/* file Contact.cpp */

#include <QGridLayout>
#include "Contact.h"

namespace ind = programmiamo::ind;

ind::Contact::Contact(QWidget *parent, QString name, QString surname, QString addr, QString pnum, QString email) : QWidget(parent) {

	/* crea cinque etichette di testo per il nome, il cognome... */

	this->name = new QLabel(name, this);
	this->surname = new QLabel(surname, this);
	this->addr = new QLabel(addr, this);
	this->pnum = new QLabel(pnum, this);
	this->email = new QLabel(email, this);

	/* crea una griglia per gestire il layout dell'interfaccia grafica */

	QGridLayout *layout = new QGridLayout(this);

	/* aggiunge le etichette alla griglia */

	layout->addWidget(this->name, 0, 0);
	layout->addWidget(this->surname, 0, 1);
	layout->addWidget(this->addr);
	layout->addWidget(this->pnum);
	layout->addWidget(this->email);

	this->setLayout(layout);
}

