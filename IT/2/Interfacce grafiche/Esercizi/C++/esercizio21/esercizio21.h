#ifndef ESERCIZIO21__H__
#define ESERCIZIO21__H__

#include <QWidget>
#include <QLabel>
#include <QEvent>

class esercizio21 : public QWidget
{
Q_OBJECT
private:
	QLabel *label;
public:
	esercizio21(QWidget *parent=NULL);
public slots:
	virtual void enterEvent(QEvent *e);
	virtual void leaveEvent(QEvent *e);
};

#endif  // ESERCIZIO21__H__

