/*
file esercizio32.cpp
compilare con: g++ -std=c++11 esercizio32.cpp
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

/* la classe Content rappresenta un contenuto generico: un libro, brano o video */
class Content {
	private:
		string title;
		string year;

	public:
		Content(string, string);
		// ~Content() = default;
		string getTitle() const;
		void setTitle(string);
		string getYear() const;
		void setYear(string);

	protected:
		virtual string printLib() const;

	friend ostream& operator<<(ostream& os, const Content&);
};

Content::Content(string title, string year)
{
	this->setTitle(title);
	this->setYear(year);
}

string Content::getTitle() const {
	return this->title;
}

void Content::setTitle(string title) {
	this->title = title;
}

string Content::getYear() const {
	return this->year;
}

void Content::setYear(string year) {
	this->year = year;
}

string Content::printLib() const {
	return "\"" + this->title + "\" (" + this->year + ")";
}

ostream& operator<<(ostream& os, const Content& c) {
	return os << c.printLib();
}

class Book : public Content {
	private:
		string author;

	public:
		Book(string, string, string);
		string getAuthor() const;
		void setAuthor(string);

	protected:
		string printLib() const override;
};

Book::Book(string title, string author, string year) : Content(title, year) {
	this->setAuthor(author);
}

string Book::getAuthor() const {
	return this->author;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::printLib() const {
	return "\"" + this->getTitle() + "\" (" + this->getYear() + "), di " + this->author;
}

class Song : public Content {
	private:
		string author;
		string singer;

	public:
		Song(string title, string, string, string);

		string getAuthor();
		void setAuthor(string);
		string getSinger();
		void setSinger(string);

	protected:
		string printLib() const override;
};

Song::Song(string title, string author, string singer, string year) : Content(title, year) {
	this->setAuthor(author);
	this->setSinger(singer);
}

string Song::getAuthor() {
	return this->author;
}

void Song::setAuthor(string author) {
	this->author = author;
}

string Song::getSinger() {
	return this->singer;
}

void Song::setSinger(string singer) {
	this->singer = singer;
}

string Song::printLib() const {
	return "\"" + this->getTitle() + "\" (" + this->getYear() + "), scritta da " + this->author + " e cantata da " + this->singer;
}

class Film : public Content {
	private:
		string director;
		string screenwriter;

	public:
		Film(string title, string director, string screenwriter, string year);
		string getDirector() const;
		void setDirector(string director);
		string getScreenwriter() const;
		void setScreenwriter(string screenwriter);

	protected:
		string printLib() const override;
};

Film::Film(string title, string director, string screenwriter, string year) : Content(title, year) {
	this->setDirector(director);
	this->setScreenwriter(screenwriter);
}

string Film::getDirector() const {
	return this->director;
} 

void Film::setDirector(string director) {
	this->director = director;
}

string Film::getScreenwriter() const {
	return this->screenwriter;
}

void Film::setScreenwriter(string screenwriter) {
	this->screenwriter = screenwriter;
}

string Film::printLib() const {
	return "\"" + this->getTitle() + "\" (" + this->getYear() + "), diretto da " + this->director + " e sceneggiato da " + this->screenwriter;
}

class Library {
	private:
		vector<Content*> titles;

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
	this->titles.push_back(new Film("Psycho", "Alfred Hitchcock", "Joseph Stefano", "1960"));
	this->titles.push_back(new Film("2001 Odissea nello spazio", "Stanley Kubrick", "Arthus C. Clarke", "1968"));
	this->titles.push_back(new Film("Shining", "Stanley Kubrick", "S. Kubrick & D. Johnson", "1980"));
}

Library::~Library() {
	for (Content* c : titles) {
		delete c;
	}
}

void Library::printLib() {
	cout << "Titoli disponibili: " << endl << endl;

	int i = 1;
	for (Content* c : titles) {
		cout << i << ". " << *c << "." << endl;
		i++;
	}

	cout << endl;
}

void Library::loop() {
	cout << "+++++++ Benvenuto nella biblioteca multimediale +++++++" << endl << "Puoi lasciare o prendere in prestito libri, musica e video." << endl;

	// stampa i libri disponibili
	printLib();

	while (true) {
		cout << "a. Prendi qualcosa in prestito" << endl << "b. Aggiungi un nuovo contenuto" << endl << "c. Esci" << endl << endl;

		string opt;
		getline(cin, opt);

		if (opt == "a") {
			cout << "Cosa vuoi in prestito? " << endl;

			cout << "Titolo: ";
			string title;
			getline(cin, title);

			transform(title.begin(), title.end(), title.begin(), ::tolower);

			bool f = false;

			for (Content *media : titles) {
				string t = media->getTitle();
				transform(t.begin(), t.end(), t.begin(), ::tolower);

				if (title == t) {
					f = true;
					if (dynamic_cast<Book*>(media)) {
						Book *book = dynamic_cast<Book*>(media);
						cout << "Trovato il libro " << *book << "." << endl << endl;
					}
					if (dynamic_cast<Song*>(media)) {
						Song *song = dynamic_cast<Song*>(media);
						cout << "Trovata la canzone " << *song << "." << endl << endl;
					}
					if (dynamic_cast<Film*>(media)) {
						Film *film = dynamic_cast<Film*>(media);
						cout << "Trovato il film " << *film << "." << endl << endl;
					}
					break;
				}
			}

			if (!f) cout << "Titolo non trovato!" << endl << endl;
		}
		/* salva un nuovo titolo (libro, canzone o ) nella mediateca */
		else if (opt == "b") {
			cout << "Cosa hai portato di nuovo?" << endl << endl << "a) Un libro" << endl << "b) Un brano audio" << endl << "c) Un film / video" << endl << endl;

			string type;
			getline(cin, type);

			// controlla che l'opzione scelta sia 'a', 'b' o 'c'
			if (type.size() != 1 || ((int)type[0] < 97 || (int)type[0] > 99)) {
				cout << "Contenuto sconosciuto!" << endl << endl;
				continue;
			}

			Content *media = NULL;

			cout << "Titolo: ";
			string title;
			getline(cin, title);

			cout << "Anno: ";
			string year;
			getline(cin, year);

			/* salva un nuovo libro */
			if (type == "a") {
				cout << "Autore: ";

				string author;
				getline(cin, author);

				media = new Book(title, author, year);
				cout << "Aggiunto il libro " << *media << "." << endl;
			}
			/* salva un nuovo brano audio */
			else if (type == "b") {
				cout << "Autore: ";
				string author;
				getline(cin, author);

				cout << "Cantante: ";
				string singer;
				getline(cin, singer);

				media = new Song(title, author, singer, year);
				cout << "Aggiunta la canzone " << *media << "." << endl;
			}
			/* salva un nuovo film */
			else if (type == "c") {
				cout << "Regista: ";
				string director;
				getline(cin, director);

				cout << "Sceneggiatore: ";
				string screenwriter;
				getline(cin, screenwriter);

				media = new Film(title, director, screenwriter, year);
				cout << endl << "Aggiunto il film " << *media << "." << endl;
			}

			titles.push_back(media);
			printLib();
		}
		else if (opt == "c") {
			cout << "Buon divertimento, speriamo di rivederti presto." << endl;
			break;
		}
		else {
			cout << "Opzione sconosciuta!" << endl;
		}
	}
}

int main() {
	Library mediateca;

	// apre la biblioteca
	mediateca.loop();
}

