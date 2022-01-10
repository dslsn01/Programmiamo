/* file esercizio20.h */

#ifndef ESERCIZIO20__H__
#define ESERCIZIO20__H__

#include <QWidget>
#include <QLabel>

class Esercizio20 : public QWidget 
{
	Q_OBJECT
public:
	Esercizio20(QWidget *parent=NULL);
public slots:
	void onSelectItem(QString);
};

#endif  // ESERCIZIO20__H__

