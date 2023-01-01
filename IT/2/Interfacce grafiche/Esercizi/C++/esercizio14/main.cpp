/* file main.cpp */

#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>
#include "esercizio14.h"

int main(int argc, char* argv[]) 
{
	QApplication application(argc, argv);

	Esercizio14 widget;
	widget.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, widget.size(), application.desktop()->availableGeometry()));

	return application.exec();
}

