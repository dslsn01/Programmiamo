/* file multipleInheritance.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

class Animal 
{
	public:
		void walk();
};

void Animal::walk()
{
	cout << "Sto passeggiando." << endl;
}

class Flyer 
{
	public:
		void takeFlight();
};

void Flyer::takeFlight()
{
	cout << "Sto decollando!" << endl;
}

/* la classe Person estende le classi Animal e Flyer */

class Person : public Animal, public Flyer 
{
};

int main()
{
	Person *p = new Person();

	cout << "p è un animale? " << boolalpha << (bool)dynamic_cast<Animal*>(p) << endl << "p è un pilota di aereo? " << (bool)dynamic_cast<Flyer*>(p) << endl;

	/* invoca le funzioni membro ereditate da entrambe le superclassi */

	p->walk();
	p->takeFlight();

	delete p;
}

