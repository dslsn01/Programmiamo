/* file Person3.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person {
	private:
		string name;
		string surname;

	public:
		Person(string, string);
		void setName(string name);
		void setSurname(string surname);
		string getName();
		string getSurname();

		/* dichiarazione della funzione membro walk() */

		void walk();
};

Person::Person(string name, string surname)
{
	this->setName(name);
	this->setSurname(surname);
}

/* implementazione dei setter e getter del nome */

void Person::setName(string name) {
	this->name = !name.empty() ? name : "John";
}

string Person::getName() 
{
	return this->name;
}

/* implementazione dei setter e getter del cognome */ 

void Person::setSurname(string surname) {
	this->surname = !surname.empty() ? surname : "Doe";
}

string Person::getSurname()
{
	return this->surname;
}

/* implementazione della funzione membro walk() */

void Person::walk()
{
	cout << this->getName() << " " << this->getSurname() << " passeggia." << endl;
}

int main()
{
	Person p("Walt", "Disney");
	p.walk();

	p = Person("", "");
	p.walk();
}

