/*
file esercizio9.cpp 
passare un parametro da linea di comando, per esempio
./esercizio9 'Ciao, mondo!' (Attenzione ai singoli apici) 
*/

#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	QString arg = argc > 1 ? argv[1] : "La tua stringa";

	QLabel label(arg);
	label.show();

	return application.exec();
}

