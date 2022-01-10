/* file esercizio14.h */

#ifndef ESERCIZIO14__H__
#define ESERCIZIO14__H__

#include <QWidget>
#include <QPushButton>

class Esercizio14 : public QWidget 
{
Q_OBJECT
private:
	QPushButton *button;

public:
	Esercizio14(QWidget *parent=NULL);

private slots:
    void showPopUp();
};

#endif  // ESERCIZIO14__H__

