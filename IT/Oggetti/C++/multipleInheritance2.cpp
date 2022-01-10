/* file multipleInheritanceIssues.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Organism {
	protected:
		string taxa;
};

/* è necessario includere la parola chiave virtual */
class Animal : public virtual Organism 
{
};

/* è necessario includere la parola chiave virtual */
class Flyer : public virtual Organism
{
};

class Person : public Animal, public Flyer
{
	private:
		string name;

	public: 
		Person(string);
		void info();
};

Person::Person(string name)
{
	this->name = name;
	this->taxa = "Homo Sapiens Sapiens";
}

void Person::info() 
{
	cout << "Ciao, sono " << this->name << " e sono un essere vivente della specie \"" << this->taxa << "\"!" << endl;
}

int main()
{
	Person *p = new Person("Neil Armstrong");

	/* l'oggetto p ha ereditato due differenti versioni della variabile taxa */

	p->info();

	delete p;
}

