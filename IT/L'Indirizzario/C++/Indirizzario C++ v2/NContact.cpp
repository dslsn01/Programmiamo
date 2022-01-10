/* file NContact.cpp */

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialogButtonBox>
#include "MainFrame.h"
#include "NContact.h"

namespace ind = programmiamo::ind;

ind::NContact::NContact(QWidget *parent) : QDialog(parent)
{
	/* crea un pannello contenitore per i campi di testo editabile */

	QWidget* panel = new QWidget(this);

	/* crea cinque campi di testo editabile per inserire il nome, il cognome... */

	this->name = new QLineEdit("Nome", panel);
	this->surname = new QLineEdit("Cognome", panel);
	this->addr = new QLineEdit("Indirizzo", panel);
	this->pnum = new QLineEdit("Numero di telefono", panel);
	this->email = new QLineEdit("E-mail", panel);

	/* crea una griglia per disporre i campi di testo */

	QGridLayout* grLayout = new QGridLayout(panel);

	/* aggiunge le etichette alla griglia */

	grLayout->setMargin(0);
	grLayout->setSpacing(0);
	grLayout->addWidget(name, 0, 0);
	grLayout->addWidget(surname, 0, 1);
	grLayout->addWidget(addr);
	grLayout->addWidget(pnum);
	grLayout->addWidget(email);

	/* associa la griglia al pannello intermedio */

	panel->setLayout(grLayout);

	/* crea un pannello contenitore per i pulsanti */

	QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	buttons->setCenterButtons(true);

	/* gestisce il click sul bottone "Ok" */

	connect(buttons, SIGNAL(accepted()), this, SLOT(accept()));

	/* gestisce il click sul bottone "Annulla" */

	connect(buttons, SIGNAL(rejected()), this, SLOT(reject()));

	/* dispone in una striscia verticale la griglia e il pannello con i pulsanti */

	QVBoxLayout *bLayout = new QVBoxLayout(this);

	bLayout->addWidget(panel);
	bLayout->addWidget(buttons);

	this->setLayout(bLayout);

	this->setWindowTitle("Inserisci contatto");
	this->setWindowModality(Qt::ApplicationModal);
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->show();
}

