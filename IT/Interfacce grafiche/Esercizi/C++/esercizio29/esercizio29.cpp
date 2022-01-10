/* file esercizio29.cpp */

#include <QApplication>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMenuBar>
#include <QLabel>
#include <QFileInfo>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QStringList>

#include <QFileDialog>
#include <QDebug>
#include <QSignalMapper>

#include "esercizio29.h"

Esercizio29::Esercizio29(QWidget *parent, QString fileName) : QMainWindow(parent), fileName(fileName)
{
	QMenu *fileMenu = menuBar()->addMenu("&File");

	QAction *newf = new QAction("Nuovo", this);
	QAction *openf = new QAction("Apri", this);
	QAction *svf = new QAction("Salva", this);
	QAction *svfn = new QAction("Salva con nome", this);
	QAction *exit = new QAction("Esci", this);

	fileMenu->addAction(newf);
	fileMenu->addAction(openf);
	fileMenu->addAction(svf);
	fileMenu->addAction(svfn);
	fileMenu->addAction(exit);

	QSignalMapper *smp = new QSignalMapper(this);
	connect(svf, SIGNAL(triggered()), smp, SLOT(map()));
	connect(svfn, SIGNAL(triggered()), smp, SLOT(map()));

	smp->setMapping(svf, false);
	// smp->setMapping(, );

	connect(newf, SIGNAL(triggered()), this, SLOT(nfile()));
	connect(openf, SIGNAL(triggered()), this, SLOT(ofile()));
	connect(smp, SIGNAL(mapped(int)), this, SLOT(saveFile(int)));
	// connect(svfn, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(exit, SIGNAL(triggered()), this, SLOT(exit()));

	textArea = new QTextEdit();
	// QString qFileName = QString::fromUtf8(fileName.c_str());

	/*
	if (QFileInfo(fileName).exists()) {
		QFile fname(fileName);
		fname.open(QIODevice::ReadOnly);
		QTextStream docReader(&fname);

		while (!docReader.atEnd()) {
			QString row = fname.readLine();
			cout << row.toUtf8().constData() << endl;
			textArea->insertPlainText(row);
		}

		fname.close();
	}
	else {
		QMessageBox::critical(this, "Errore!", "Il file selezionato non esiste!");
	}
	*/

	QLabel *label = new QLabel("<nuovo>");
	label->setAlignment(Qt::AlignCenter);

	textArea = new QTextEdit();

	QWidget *container = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout();

	layout->addWidget(label);
	layout->addWidget(textArea);

	container->setLayout(layout);

	this->setCentralWidget(container);
	this->setWindowTitle(QString::fromUtf8("ProgEdit"));
	this->resize(640, 480);
	this->show();
}

// nuovo file
void Esercizio29::nfile() {
	this->fileName = "";
	// self.vText.set("<nuovo>")
	// self.textArea.delete(1.0, END)
	this->textArea->clear();
}

// apri file
void Esercizio29::ofile() {
	QString fname = QFileDialog::getOpenFileName(this, tr("Apri nome: "), ".", tr("text files (*.txt);; all files (*)"));
	if (!fname.isEmpty()) {
		int index = fname.lastIndexOf("/");
		QString l = fname.mid(index+1, fname.size());
		// qDebug() << l;
		// fname.name.split("/")[-1]
		this->fileName = fname;
		// self.vText.set(fileName)
		this->textArea->clear();

		if (QFileInfo(fname).exists()) {
			QFile file(fname);
			file.open(QIODevice::ReadOnly);
			QTextStream ts(&file);

			while (!ts.atEnd()) {
				textArea->insertPlainText(file.readLine());
			}

			file.close();
		}
	}
}

void Esercizio29::saveFile(int swn)
{
	if (this->fileName.isEmpty() || swn) {
		// QFileDialog fc(this);
		// fc.setDirectory(".");
		// fc.setNameFilters("all files (*)");
		// fc.setFileMode(QFileDialog::AnyFile);
		// if (fc.exec()) {
		// 	
		// }
		QString fname = QFileDialog::getSaveFileName(this, tr("Salva come..."), ".", tr("all files (*)"));
		// qDebug() << fname;
		if (fname.isEmpty()) return;
		// fname.mid(fname.lastIndexOf("/"), fname.size());
		this->fileName = fname;
		// .split("/")[-1]
		// self.vText.set("\"{}\"".format(self.fileName));
	}

	QFile file(this->fileName);
	file.open(QIODevice::ReadWrite);
	QTextStream ts(&file);

	QString txt = textArea->toPlainText();
	QStringList lines = txt.split("\n");

	for (int i = 0; i < lines.size(); i++) {
		ts << lines[i] << "\n";
	}

	file.close();

	// QMessageBox::information(this, "Avviso", "File salvato con successo");
}

void Esercizio29::exit() {
	QApplication::quit();
}

