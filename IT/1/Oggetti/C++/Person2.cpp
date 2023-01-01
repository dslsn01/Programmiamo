/* file Person2.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

/* interfaccia della classe Person */

class Person {
	/* definizione delle variabili membro "name" e "surname" */
	public:
		string name;
		string surname;

	/* costruttore e distruttore della classe */
	public:
		Person(string, string);
		~Person();
};

/* implementazione della classe Person: il costruttore della classe inizializza "name" e "surname" */

Person::Person(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}

Person::~Person()
{
	cout << "Una persona è stata cancellata." << endl;
}

int main() 
{
	/* creazione STATICA di un oggetto */

	Person p1("John", "Doe");

	/* creazione DINAMICA di un oggetto, con l'operatore new */

	Person *p2 = new Person("Jane", "Doe");

	cout << "L'uomo si chiama " << p1.name << " " << p1.surname << "." << endl;
	cout << "La donna si chiama " << p2->name << " " << p2->surname << "." << endl;

	/* cancella l'oggetto con l'operatore delete */

	delete p2;
}

