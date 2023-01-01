/* file MainFrame.h */

#ifndef MAINFRAME__H__
#define MAINFRAME__H__

#include <QMainWindow>
#include <QTabWidget>
#include <QSqlDatabase>

namespace programmiamo {
	namespace ind {
		class MainFrame : public QMainWindow 
		{
		Q_OBJECT

		private:
			QTabWidget *tabs;
			QSqlDatabase db;

		public:
			MainFrame(QWidget *parent = NULL);
			void updateUI();

		private slots:
			void save();
			void remove();
			void exit();
		};
	}
}

#endif // MAINFRAME__H__

