/* file esercizio16.h */

#ifndef ESERCIZIO16__H__
#define ESERCIZIO16__H__

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class Esercizio16 : public QWidget 
{
Q_OBJECT
private:
	QTextEdit *text;
	QPushButton *button1;
	QPushButton *button2;

public:
	Esercizio16(QWidget *parent=NULL);

private slots:
	void btn1ClickHandler();
	void btn2ClickHandler();
};

#endif  // ESERCIZIO16__H__

