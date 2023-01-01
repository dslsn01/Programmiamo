/* file esercizio13.h */

#ifndef ESERCIZIO13__H__
#define ESERCIZIO13__H__

#include <QWidget>
#include <QPushButton>

class Esercizio13 : public QWidget 
{
Q_OBJECT
private:
	QPushButton *button;

public:
	Esercizio13(QWidget *parent=NULL);

private slots:
    void close();
};

#endif  // ESERCIZIO13__H__

