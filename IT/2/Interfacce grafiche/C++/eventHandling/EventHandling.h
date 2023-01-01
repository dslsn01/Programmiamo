/* file EventHandling.h */

#ifndef EVENTHANDLING__H__
#define EVENTHANDLING__H__

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

class EventHandling : public QWidget
{
Q_OBJECT
private:
	QTextEdit *text;
	QPushButton *button;

public:
	EventHandling(QWidget *parent = NULL);

private slots:
	void clickHandler();
};

#endif // EVENTHANDLING__H__

