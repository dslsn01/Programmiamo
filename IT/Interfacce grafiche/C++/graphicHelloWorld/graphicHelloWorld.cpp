/* file graphicHelloWorld.cpp */

#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	/* crea l'applicazione principale */

	QApplication application(argc, argv);

	/* crea un'etichetta di testo */

	QLabel label("Ciao, mondo!");

	/* rende visibile l'etichetta */

	label.show();

	/* inizia il ciclo di vita dell'applicazione */

	return application.exec();
}

