/* file esercizio7.cpp */

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
		string getName();
		void setName(string);
		virtual void floatInSpace();

	friend ostream& operator<<(ostream&, const Spaceman&);
};

Spaceman::Spaceman(string name)
{
	this->setName(name);
}

string Spaceman::getName() {
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
};

class Explorer : public Spaceman {
	public:
		Explorer(string name);
};

Pilot::Pilot(string name) : Spaceman(name) {}

Explorer::Explorer(string name) : Spaceman(name) {}

int main()
{
	Pilot buzz("Buzz Aldrin");
	Explorer neil("Neil Armstrong");

	cout << buzz << endl;
	cout << neil << endl;
}

