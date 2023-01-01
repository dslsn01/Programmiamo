/*
file esercizio31.cpp
compilare con: g++ -std=c++11 esercizio31.cpp
*/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::vector;

/* la classe Book rappresenta un libro */
class Book {
	private:
		string title;
		string author;
		string year;

	public:
		Book(string, string, string);
		string getTitle() const;
		void setTitle(string);
		string getAuthor() const;
		void setAuthor(string);
		string getYear() const;
		void setYear(string);

	friend ostream& operator<<(ostream& os, const Book&);
};

Book::Book(string title, string author, string year) {
	this->setTitle(title);
	this->setAuthor(author);
	this->setYear(year);
}

string Book::getTitle() const {
	return this->title;
}

void Book::setTitle(string title) {
	this->title = title;
}

string Book::getAuthor() const {
	return this->author;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getYear() const {
	return this->year;
}

void Book::setYear(string year) {
	this->year = year;
}

ostream& operator<<(ostream& os, const Book& b) {
	return os << "\"" << b.title << "\" (" << b.year << "), di " << b.author;
}

class Library {
	private: 
		vector<Book*> titles;

	public:
		Library();
		virtual ~Library();
		void loop();

	private:
		void printLib();
};

Library::Library() {
	this->titles.push_back(new Book("Ulisse", "James Joyce", "1922"));
	this->titles.push_back(new Book("On the road", "Jack Kerouac", "1951"));
	this->titles.push_back(new Book("Il nome della rosa", "Umberto Eco", "1980"));
}

Library::~Library() {
	for (Book* b : titles) {
		delete b;
	}
}

void Library::printLib() {
	cout << "Libri disponibili: " << endl << endl;

	int i = 1;
	for (auto& b : titles) {
		cout << i << ". " << *b << "." << endl;
		i++;
	}

	cout << endl;
}

void Library::loop() {
	cout << "+++++++ Benvenuto in biblioteca +++++++" << endl;

	// stampa i libri disponibili
	printLib();

	while (true) {
		cout << "a. Prendi un libro in prestito" << endl << "b. Aggiungi un nuovo libro" << endl << "c. Esci" << endl << endl;

		string opt;
		getline(cin, opt);

		if (opt == "a") {
			cout << "Prendi un libro in prestito." << endl;

			cout << "Titolo: ";
			string title;
			getline(cin, title);

			transform(title.begin(), title.end(), title.begin(), ::tolower);

			bool f = false;

			for (Book *book : titles) {
				string t = book->getTitle();
				transform(t.begin(), t.end(), t.begin(), ::tolower);

				if (title == t) {
					cout << "Trovato il libro " << *book << "." << endl << endl;
					f = true;
					break;
				}
			}

			if (!f) cout << "Libro non trovato!" << endl;
		}
		/* salva un nuovo libro nella biblioteca */
		else if (opt == "b") {
			cout << "Aggiungi un nuovo libro." << endl;

			cout << "Titolo: ";
			string title;
			getline(cin, title);

			cout << "Autore: ";
			string author;
			getline(cin, author);

			cout << "Anno: ";
			string year;
			getline(cin, year);

			Book *book = new Book(title, author, year);

			titles.push_back(book);

			cout << "Aggiunto il libro " << *book << "." << endl;
			printLib();
		}
		else if (opt == "c") {
			cout << "Buona lettura, speriamo di rivederti presto." << endl;
			break;
		}
		else {
			cout << "Opzione sconosciuta!" << endl;
		}
	}
}

int main() {
	Library biblio;

	// apre la biblioteca
	biblio.loop();
}

