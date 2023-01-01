/* file printPerson.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Person {
	private:
		string name;
		string surname;

	public:
		Person(string name, string surname);

	friend ostream& operator<<(ostream &os, const Person &person);
};

Person::Person(string name, string surname)
{
	this->name = name;
	this->surname = surname;
}

ostream& operator<<(ostream &os, const Person& person) {
	os << "La persona si chiama " << person.name << " " << person.surname;
	return os;
}

int main()
{
	Person person("John", "Doe");
	cout << person << endl;
}
