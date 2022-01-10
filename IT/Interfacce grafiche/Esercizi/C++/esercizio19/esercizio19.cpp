/* file esercizio19.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include <QComboBox>
#include "esercizio19.h"

Esercizio19::Esercizio19(QWidget *parent) : QWidget(parent)
{
	QComboBox *lang = new QComboBox(this);
	lang->addItem("italiano");
	lang->addItem("inglese");

	this->label = new QLabel("Ciao!", this);
	connect(lang, SIGNAL(currentIndexChanged(QString)), this, SLOT(onSelectItem(QString)));

	QVBoxLayout *layout = new QVBoxLayout(this);

	layout->addWidget(this->label);
	layout->addWidget(lang);
	this->setLayout(layout);

	this->resize(190, 50);
	this->setWindowTitle("Scegli la tua lingua");
	this->show();
}

void Esercizio19::onSelectItem(QString s) {
	if (s == "italiano") {
		this->label->setText("Ciao!");
	}
	if (s == "inglese") {
		this->label->setText("Hello!");
	}
}

