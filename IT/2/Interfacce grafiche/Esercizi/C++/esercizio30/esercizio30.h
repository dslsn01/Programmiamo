/* file esercizio30.h */

#ifndef ESERCIZIO30__H__
#define ESERCIZIO30__H__

#include <QWidget>
#include <QVector>
#include <QTextEdit>
#include <QVarLengthArray>

class Calc;

class KPad : public QWidget
{
Q_OBJECT
private:
	Calc *calc;
	/*QString*/const char* btns[23] = { "7", "8", "9", "÷", "CE", "C", "4", "5", "6", "∗", "(", ")", "1", "2", "3", "-", "x²", "√", "0", ".", "%", "+", "=" };
	//"/", "*", "^2"

public:
	KPad(QWidget*);

private slots:
	void btnHandler();
};

class Calc : public QWidget
{
Q_OBJECT
private:
	static /*const*/ QHash<QString, QVarLengthArray<int> > ops;
	static QHash<QString, QVarLengthArray<int> > initOperators();
public:
	QTextEdit *scr;

public:
	Calc(QWidget *parent=NULL);

// private:
public:
	QVector<QString> infixToRpn(QString);
	double evaluate(QVector<QString>&);
};

#endif  // ESERCIZIO30__H__

