/* file esercizio13.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

/* "astronauti" e "passeggeri" sono tutti "persone": "Person" è la superclasse comune */

class Person {
	private:
		string name;

	public:
		Person(string);
		string getName() const;
		void setName(string);
};

Person::Person(string name)
{
	this->setName(name);
}

string Person::getName() const {
	return this->name;
}

void Person::setName(string name) {
	this->name = name;
}

class Spaceman : public Person {
	public:
		Spaceman(string);
		void floatInSpace();

	friend ostream& operator<<(ostream&, const Spaceman&);
};

Spaceman::Spaceman(string name) : Person(name) {}

void Spaceman::floatInSpace() {
	cout << this->getName() << " si muove nello spazio..." << endl;
}

ostream& operator<<(ostream& os, const Spaceman& s) {
	os << "Sono l'astronauta " << s.getName();
	return os;
}

class Passenger : public Person {
	public:
		Passenger(string);
};

Passenger::Passenger(string name) : Person(name) {}

class Spaceshuttle {
	public:
		void welcome(Person&);
};

void Spaceshuttle::welcome(Person& p) {
	cout << "Benvenuto sullo shuttle, " << p.getName() << "!" << endl;
}

int main()
{
	Spaceman buzz("Buzz Aldrin");
	Spaceman neil("Neil Armstrong");
	Passenger jBloggs("Joe Bloggs");

	Spaceshuttle shuttle;

	/* il metodo welcome() dello Spaceshuttle può ricevere una persona generica */

	shuttle.welcome(buzz);
	shuttle.welcome(neil);
	shuttle.welcome(jBloggs);
}

