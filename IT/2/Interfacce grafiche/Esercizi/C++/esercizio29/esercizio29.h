/* file esercizio29.h */

#ifndef ESERCIZIO29__H__
#define ESERCIZIO29__H__

#include <QWidget>
#include <QMainWindow>
#include <QTextEdit>

class Esercizio29 : public QMainWindow
{
Q_OBJECT
private:
	QString fileName;
	// aggiungere QLabel
	QTextEdit *textArea;

public:
	Esercizio29(QWidget *parent=NULL, QString fileName="");

private slots:
	void nfile();
	void ofile();
	void saveFile(int);
	void exit();
};

#endif  // ESERCIZIO29__H__

