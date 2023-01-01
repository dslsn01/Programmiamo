/* file esercizio12.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

/* gli "astronauti" sono tutti "persone": "Person" è la superclasse comune */

class Person {
	/* ogni persona ha un nome: la proprietà "nome" è dichiarata nella superclasse Person. */
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

class Traveler {
};

class Spaceman : public virtual Person, public virtual Traveler {
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
	os << "Sono l'astronauta " << s.getName() << ".";
	return os;
}

int main()
{
	Spaceman *neil = new Spaceman("Neil Armstrong");

	if (dynamic_cast<Person*>(neil)) {
		cout << "L'astronauta " << neil->getName() << " è una persona!"  << endl;
	}

	if (dynamic_cast<Traveler*>(neil)) {
		cout << "L'astronauta " << neil->getName() << " è un viaggiatore!" << endl;
	}

	delete neil;
}

