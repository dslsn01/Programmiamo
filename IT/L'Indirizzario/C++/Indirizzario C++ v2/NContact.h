/* file NContact.h */

#ifndef NCONTACT__H__
#define NCONTACT__H__

#include <QDialog>
#include <QWidget>
#include <QLineEdit>

namespace programmiamo {
	namespace ind {
		class NContact : public QDialog
		{
		Q_OBJECT
		private:
			QLineEdit *name;
			QLineEdit *surname;
			QLineEdit *addr;
			QLineEdit *pnum;
			QLineEdit *email;
	
		public:
			NContact(QWidget*);
		};
	}
}

#endif // NCONTACT__H__

