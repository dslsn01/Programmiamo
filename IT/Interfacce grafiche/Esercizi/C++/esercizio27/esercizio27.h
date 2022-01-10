/* file esercizio27.h */

#ifndef ESERCIZIO27__H__
#define ESERCIZIO27__H__

#include <QWidget>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QImage>

class Esercizio27 : public QWidget
{
Q_OBJECT

private:
	int x0 = -1.0;
	int y0 = -1.0;
	QImage canvas;

public:
	Esercizio27(QWidget *parent=NULL);

public slots:
	void mousePressEvent(QMouseEvent*) override;
	void mouseReleaseEvent(QMouseEvent*) override;
	void paintEvent(QPaintEvent*) override;
};

#endif  // ESERCIZIO27__H__

