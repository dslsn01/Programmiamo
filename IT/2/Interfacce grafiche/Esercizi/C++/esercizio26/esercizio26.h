/* file esercizio26.h */

#ifndef ESERCIZIO26__H__
#define ESERCIZIO26__H__

#include <QWidget>
#include <QPaintEvent>
#include <QImage>
#include <QVector>
#include <QPolygonF>

class Esercizio26 : public QWidget
{
Q_OBJECT

private:
	QVector<QPolygonF> ngons;
	QImage canvas;

public:
	Esercizio26(QWidget *parent=NULL);

public slots:
	void paintEvent(QPaintEvent*) override;

private:
	void addPolygon(int, int, int);
};

#endif  // ESERCIZIO26__H__

