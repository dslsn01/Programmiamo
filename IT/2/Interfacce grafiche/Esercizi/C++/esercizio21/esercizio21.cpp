#include <QApplication>
#include <QVBoxLayout>
#include "esercizio21.h"

esercizio21::esercizio21(QWidget *parent) : QWidget(parent)
{
	this->resize(150, 100);
	this->show();
}

void esercizio21::enterEvent(QEvent*) {
	this->setStyleSheet("background-color: green;");
}

void esercizio21::leaveEvent(QEvent*) {
	this->setStyleSheet("");
}

