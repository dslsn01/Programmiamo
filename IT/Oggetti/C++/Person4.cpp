/* file Person3.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person {
	public:
		string name;
		string surname;

	public:
		Person();

		/* dichiarazione della funzione membro walk() */

		void walk();
};

Person::Person()
{
	this->name = "John";  
	this->surname = "Doe";
}

/* implementazione della funzione membro walk() */

void Person::walk()
{
	cout << this->name << " " << this->surname << " passeggia." << endl;
}

int main() 
{
	Person p1;
	p1.walk();

	Person *p2 = new Person();
	p2->walk();

	delete p2;
}

