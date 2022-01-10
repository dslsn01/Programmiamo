#ifndef ESERCIZIO15__H__
#define ESERCIZIO15__H__

#include <QMainWindow>

class Esercizio15 : public QMainWindow 
{
Q_OBJECT
public:
	Esercizio15(QWidget *parent=NULL);

private slots:
	void closeHandler();
};

#endif  // ESERCIZIO15__H__

