/* file esercizio30.cpp */

#include <QtGlobal>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QException>
#else
#include <QtCore>
typedef QtConcurrent::Exception QException;
#endif
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStack>
#include <cmath>
#include "esercizio30.h"

KPad::KPad(QWidget *parent) : QWidget(parent) {
	this->calc = dynamic_cast<Calc*>(parent);
	QGridLayout *layout = new QGridLayout(this);
	layout->setVerticalSpacing(0);
	layout->setHorizontalSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	int r = 0;
	int c = 0;
	for (int i = 0; i < 23; i++) {
		int colspan = 1;
		int w = 35;
		int h = 25;
		const char* txt = btns[i];
		QPushButton *button = new QPushButton(QString::fromUtf8(txt), this);
		connect(button, SIGNAL(clicked()), this, SLOT(btnHandler()));
		c++;

		if (QString(txt) == "=") {
			w = 70;
			colspan = 2;
		}
		button->setFixedSize(w, h);
		layout->addWidget(button, r, c, 1, colspan);

		if (c % 6 == 0) {
			c = 0;
			r++;
		}
	}

	setLayout(layout);
}

void KPad::btnHandler()
{
	QPushButton *src = qobject_cast<QPushButton*>(sender());
	QString s = src->text();
	if (s == "=") {
		QString output;
		QString expr = this->calc->scr->toPlainText();
		try {
			QVector<QString> rpn = this->calc->infixToRpn(expr);
			double result = this->calc->evaluate(rpn);
			output = QString::number(result);
		}
		catch (QException& e) {
			// stampa msg di errore sullo schermo
			output = "Espressione malformata";
		}

		this->calc->scr->clear();
		this->calc->scr->insertPlainText(output);
		this->calc->scr->setAlignment(Qt::AlignRight);
	}
	else if (s == "C") {
		this->calc->scr->clear();
		this->calc->scr->setAlignment(Qt::AlignRight);
	}
	else if (s == "CE") {
		QString onsc = this->calc->scr->toPlainText();
		QString lastN = "";
		QRegExp rx("[\\d]+(\\.[\\d]+)?");
		int pos = 0;
		while ((pos = rx.indexIn(onsc, pos)) != -1) {
			lastN = rx.cap(0);
			pos += rx.matchedLength();
		}

		int i = onsc.lastIndexOf(lastN);
		QString l = onsc.left(i);
		this->calc->scr->clear();
		this->calc->scr->insertPlainText(l);
		this->calc->scr->setAlignment(Qt::AlignRight);
	}
	else {
		if (s == QString::fromUtf8("x²")) s.replace("x", "");
		this->calc->scr->insertPlainText(s);
	}
}

QHash<QString, QVarLengthArray<int> > Calc::ops = initOperators();

QHash<QString, QVarLengthArray<int> > Calc::initOperators() {
	QHash<QString, QVarLengthArray<int> > ops;
	QVarLengthArray<int> arr1(2);
	arr1[0] = 0;
	arr1[1] = 0;
	QVarLengthArray<int> arr2 = arr1;
	arr2[0] = 1;
	QVarLengthArray<int> arr3 = arr2;
	arr3[0] = 2;
	arr3[1] = 1;

	ops["+"] = arr1;
	ops["-"] = arr1;
	ops["*"] = arr2;
	ops["/"] = arr2;
	ops["^"] = arr3;

	return ops;
}

Calc::Calc(QWidget *parent) : QWidget(parent)
{
	int w = 180;
	int h = 120;
	scr = new QTextEdit();
	scr->setAlignment(Qt::AlignRight);
	KPad *kpad = new KPad(this);

	// posiziona le componenti con un nuovo layout

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(scr);
	// posiziona la tastiera
	layout->addWidget(kpad);
	setLayout(layout);
	resize(w, h);
	setWindowTitle("Calcolatrice");
	show();
}

QVector<QString> Calc::infixToRpn(QString expr) {
	expr.replace(QString::fromWCharArray(L"\u00b2"), "^2").replace(QString::fromWCharArray(L"\u221A"), "sqrt").replace(QString::fromWCharArray(L"\u00F7"), "/").replace(QString::fromWCharArray(L"\u2217"), "*");

	QRegExp rx("^[-+]?[\\d]+(\\.[\\d]+)?%?|[\\d]+(\\.[\\d]+)?%?|sqrt[\\d]+(\\.[\\d]+)?|[()*/+-\\^]");
	QVector<QString> tokens;
	int pos = 0;

	while ((pos = rx.indexIn(expr, pos)) != -1) {
		QString s = rx.cap(0);
		tokens.push_back(s);
		pos += rx.matchedLength();
	}

	QVector<QString> rpn;
	QStack<QString> stackOps;

	for (int i = 0; i < tokens.size(); i++) {
		QString token = tokens.at(i);
		if (ops.contains(token)) {
			QVarLengthArray<int> prop = *ops.find(token);
			int prec = prop[0];
			int ass = prop[1];

			while (!stackOps.empty() && ops.contains(stackOps.top())) {
				int opPrec = (*ops.find(stackOps.top()))[0];
				if (prec < opPrec || (prec == opPrec && ass == 0)) {
					rpn.push_back(stackOps.pop());
				}
				break;
			}
			stackOps.push(token);
		}
		else if (token == "(") {
			stackOps.push(token);
		}
		else if (token == ")") {
			while (!stackOps.empty() && stackOps.top() != "(") {
				rpn.push_back(stackOps.pop());
			}
			// gestione espressioni malformate
			if (stackOps.empty()) throw QException();
			stackOps.pop();
		}
		else {
			// numero o funzione
			// se si tratta di una funzione, la valuta e salva subito il risultato
			if (token.indexOf("sqrt") == 0) {
				QRegExp rx("[\\d]+(\\.[\\d]+)?");
				QVector<QString> tokens;
				int pos = 0;

				while ((pos = rx.indexIn(expr, pos)) != -1) {
					QString s = rx.cap(0);
					double d = s.toDouble();
					double res = sqrt(d);
					token = QString::number(res);
					pos += rx.matchedLength();
				}
			}
			rpn.push_back(token);
		}
	}

	while (!stackOps.empty()) {
		rpn.push_back(stackOps.pop());
	}

	return rpn;
}

double Calc::evaluate(QVector<QString>& rpn) {
	QStack<QString> stack;
	for (int i = 0; i < rpn.size(); i++) {
		QString token = rpn.at(i);
		if (!ops.contains(token)) {
			stack.push(token);
		}
		else {
			double o2 = 0;
			double o1 = 0;
			QString s;

			if (!stack.empty()) s = stack.pop(); else throw QException();
			if (!stack.empty()) o1 = stack.pop().toDouble(); else throw QException();

			if (!s.endsWith("%")) o2 = s.toDouble();
			else {
				// calcola la percentuale
				s.replace("%", "");
				o2 = (double) o1/100*s.toDouble();
			}

			double result = 0.0;
			if (token == "+") result = o1 + o2;
			else if (token == "-") result = o1 - o2;
			else if (token == "*") result = o1 * o2;
			else if (token == "/") result = o1 / o2;
			else if (token == "^") result = pow(o1, o2);

			stack.push(QString::number(result));
		}
	}
	return stack.pop().toDouble();
}

