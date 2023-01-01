/* file esercizio28.h */

#ifndef ESERCIZIO28__H__
#define ESERCIZIO28__H__

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QImage>
#include <QVector>
#include <QColor>
#include <QPolygonF>

class Esercizio28 : public QWidget
{
Q_OBJECT

private:
	QImage canvas;
	QVector<QPointF> coords;
	QVector<QPair<QPolygonF, QString> > ngons;
	QColor colors[6] = { "red", "orange", "yellow", "green", "blue", "cyan" };

public:
	Esercizio28(QWidget *parent=NULL);

public slots:
	void mouseReleaseEvent(QMouseEvent*) override;
	void paintEvent(QPaintEvent*) override;
};

#endif  // ESERCIZIO28__H__

