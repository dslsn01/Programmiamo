/* file Contact.h */

#ifndef CONTACT__H__
#define CONTACT__H__

#include <QWidget>
#include <QLabel>
#include <QString>

namespace programmiamo {
	namespace ind {
		class Contact : public QWidget 
		{
		public:
			QLabel *name;
			QLabel *surname;
			QLabel *addr;
			QLabel *pnum;
			QLabel *email;

		public:
			Contact(QWidget*, QString, QString, QString, QString, QString);
		};
	}
}

#endif // CONTACT__H__

