/* file EventHandling.cpp */

#include <QVBoxLayout>
#include "EventHandling.h"

EventHandling::EventHandling(QWidget *parent) : QWidget(parent)
{
	/* crea un'area di testo */

	text = new QTextEdit();

	/* crea un pulsante */

	button = new QPushButton("Cliccami!", this);

	/* associa il gestore dell'evento click al pulsante */

	connect(button, SIGNAL(clicked()), this, SLOT(clickHandler()));

	/* crea un nuovo layout per posizionare le componenti */

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(text);
	layout->addWidget(button);

	this->setLayout(layout);
	this->resize(280, 250);
	this->setWindowTitle("Ciao!");
	this->show();
}

void EventHandling::clickHandler()
{
	text->append("Click!");
}

