/* file esercizio17.h */

#ifndef ESERCIZIO17__H__
#define ESERCIZIO17__H__

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

class Esercizio17 : public QMainWindow
{
Q_OBJECT
private:
	QTextEdit *text;
	QPushButton *button1;
	QPushButton *button2;

public:
	Esercizio17(QWidget *parent=NULL);

private slots:
	void btn1ClickHandler();
	void btn2ClickHandler();
	void closeHandler();
};

#endif  // ESERCIZIO17__H__

