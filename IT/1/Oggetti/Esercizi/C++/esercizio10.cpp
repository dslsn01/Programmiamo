/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp
*/

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Spaceman {
	private:
		string name;

	public:
		Spaceman(string);
		string getName() const;
		void setName(string);
		virtual void floatInSpace();

	friend ostream& operator<<(ostream&, const Spaceman&);
};

Spaceman::Spaceman(string name)
{
	this->setName(name);
}

string Spaceman::getName() const {
	return this->name;
}

void Spaceman::setName(string name) {
	this->name = name;
}

ostream& operator<<(ostream& os, const Spaceman& s) {
	os << "Sono l'astronauta " << s.name << "!";
	return os;
}

void Spaceman::floatInSpace() {
	cout << this->getName() << " galleggia nello spazio..." << endl;
}

class Pilot : public Spaceman {
	public:
		Pilot(string name);
		void floatInSpace() override;

	friend ostream& operator<<(ostream&, const Pilot&);
};

class Explorer : public Spaceman {
	public:
		Explorer(string);
		void floatInSpace() override;

	friend ostream& operator<<(ostream&, const Explorer&);
};

Pilot::Pilot(string name) : Spaceman(name) {}

void Pilot::floatInSpace()  {
	cout << this->getName() << " naviga nello spazio alla guida dello shuttle." << endl;
}

ostream& operator<<(ostream &os, const Pilot &p) {
	os << "Sono il pilota " << p.getName() << ".";
	return os;
}

Explorer::Explorer(string name) : Spaceman(name) {}

void Explorer::floatInSpace()  {
	cout << this->getName() << " galleggia nello spazio aperto..." << endl;
}

ostream& operator<<(ostream &os, const Explorer &e) {
	os << "Sono l'esploratore " << e.getName() << ".";
	return os;
}

int main()
{
	Pilot buzz("Buzz Aldrin");
	Explorer neil("Neil Armstrong");

	buzz.floatInSpace();
	neil.floatInSpace();
}

