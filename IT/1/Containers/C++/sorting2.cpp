/* 
file sorting2.cpp
compilare con: g++ -std=c++11 sorting2.cpp
*/

#include <iostream>
#include <iterator>
#include <list>

using std::cout;
using std::endl;
using std::string;
using std::ostream_iterator;
using std::list;

class Animal {
	private:
		string name;

	public:
		Animal(const string&);
		void setName(const string&);
		string getName() const;
};

Animal::Animal(const string& name) 
{
	setName(name);
}

void Animal::setName(const string& name)
{
	this->name = name;
}

string Animal::getName() const
{
	return this->name;
}

/* funzione di confronto utilizzata dal metodo sort() */

bool compare(const Animal& first, const Animal& second) {
	return first.getName() < second.getName();
}

int main()
{
	/* crea una lista di animali */

	list<Animal> li;

	Animal tiger("tigre");
	Animal giraffe("giraffa");
	Animal elephant("elefante");
	
	li.push_back(tiger);
	li.push_back(giraffe);
	li.push_back(elephant);

	cout << "Lista originale:" << endl << "[";

	for (const auto& a : li) {
		cout << a.getName() << ", ";
	}

	cout << "\b\b]" << endl;

	li.sort(compare);

	cout << "Lista originale:" << endl << "[";

	for (const auto& a : li) {
		cout << a.getName() << ", ";
	}

	cout << "\b\b]" << endl;
}

