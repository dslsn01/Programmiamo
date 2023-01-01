/* file main.cpp */

#include <QApplication>
#include "esercizio29.h"

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	if (argc > 1) {
		QString fileName(argv[1]);
		// Esercizio29 widget(fileName);
	}
	else {
		// QMessageBox::warning(NULL, "Attenzione!", "Nessun file da leggere!");
		Esercizio29 widget;
		return application.exec();
	}
}

