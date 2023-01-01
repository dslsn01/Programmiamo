/*
file override.cpp
compilare con: g++ -std=c++11 override.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

class Animal 
{
	/* la funzione che si vuole sovrascrivere viene marcata come virtual */
	public:
		virtual void foo();
};

/* definizione originale della funzione membro foo() */

void Animal::foo() 
{
	cout << "Ciao, sono un animale!" << endl;
}

class Person : public Animal {
	public:
		void foo() override;
};

/* override della funzione membro foo() ereditata dalla superclasse Animal */

void Person::foo() 
{
	cout << "Ciao, sono una persona!" << endl;
}

int main()
{
	/* crea un'istanza della superclasse Animal */

	Animal a;

	/* ...invoca la funzione membro foo() definita nella classe Animal */

	a.foo();

	/* crea un'istanza della sottoclasse 'Person' */

	Person p;

	/* ...invoca la funzione membro foo() ridefinita nella classe Person */

	p.foo();
}

