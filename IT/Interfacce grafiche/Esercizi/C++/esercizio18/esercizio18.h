/* file esercizio18.h */

#ifndef ESERCIZIO18__H__
#define ESERCIZIO18__H__

#include <QMainWindow>
#include <QTextEdit>

class Esercizio18 : public QMainWindow
{
Q_OBJECT
private:
	QTextEdit *text;

public:
	Esercizio18(QWidget *parent=NULL);

private slots:
	void menu1ClickHandler();
	void menu2ClickHandler();
	void closeHandler();
};

#endif  // ESERCIZIO18__H__

