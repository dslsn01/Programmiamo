#ifndef ESERCIZIO22__H__
#define ESERCIZIO22__H__

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class esercizio22 : public QWidget
{
Q_OBJECT
private:
	QLabel *label;
public:
	esercizio22(QWidget *parent=NULL);
public slots:
	virtual void mouseMoveEvent(QMouseEvent *e);
};

#endif  // ESERCIZIO22__H__

