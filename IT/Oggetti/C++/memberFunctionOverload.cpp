/* file memberFunctionOverload.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person 
{
	/* sono state definite due funzioni membro con lo stesso nome e differente lista di argomenti */

	public:
		void foo();
		void foo(string name);
		
};

void Person::foo() 
{
	cout << "Ciao, mondo!" << endl;
}

void Person::foo(string name) 
{
	cout << "Ciao, " << name << "!" << endl;
}

int main() 
{
	Person *person = new Person();
	
	person->foo();
	person->foo("John Doe");

	delete person;
}

