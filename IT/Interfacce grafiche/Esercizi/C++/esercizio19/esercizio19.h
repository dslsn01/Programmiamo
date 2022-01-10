/* file esercizio19.h */

#ifndef ESERCIZIO19__H__
#define ESERCIZIO19__H__

#include <QWidget>
#include <QLabel>

class Esercizio19 : public QWidget 
{
Q_OBJECT
private:
	QLabel *label;
public:
	Esercizio19(QWidget *parent=NULL);
public slots:
	void onSelectItem(QString);
};

#endif  // ESERCIZIO19__H__

