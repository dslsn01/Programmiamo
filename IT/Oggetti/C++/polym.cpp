/* file polym.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::boolalpha;

class Animal {
	/* dichiara il campo "age" nella superclasse Animal */
	private:
		int age;

	public:
		Animal(int);
		int getAge() const;
		void setAge(int);
};

Animal::Animal(int age)
{
	this->setAge(age);
}

int Animal::getAge() const {
	return this->age;
}

void Animal::setAge(int age)
{
	this->age = age;
}

/* la classe Person estende la classe Animal ed eredita i membri */

class Person : public Animal {
	private:
		string name;
		string surname;

	public:
		Person(string name, string surname, int age);
		string getName() const;
		void setName(string);
		string getSurname() const;
		void setSurname(string);

	friend std::ostream& operator<<(std::ostream&, const Person&);
};

Person::Person(string name, string surname, int age) : Animal(age) {
	this->setName(name);
	this->setSurname(surname);
}

string Person::getName() const {
	return this->name;
}

void Person::setName(string name)
{
	this->name = name;
}

string Person::getSurname() const {
	return this->surname;
}

void Person::setSurname(string surname)
{
	this->surname = surname;
}

ostream& operator<<(ostream& os, const Person& p) {
	os << p.name << " " << p.surname << ", " << p.getAge() << " anni.";
	return os;
}

int main()
{
	/* crea un'istanza della sottoclasse Person */

	Person *p = new Person("John", "Doe", 30);

	/* verifica che p appartenga al tipo Person, ...ma anche al tipo Animal */

	cout << "p animale? " << boolalpha << (bool) dynamic_cast<Animal*>(p) << endl;
	cout << "p persona? " << boolalpha << (bool) dynamic_cast<Person*>(p) << endl;

	// risolve il puntatore e stampa l'oggetto con l'operatore "<<"
	cout << *p << endl;

	delete p;
}

