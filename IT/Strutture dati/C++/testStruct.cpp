/* file testStruct.cpp */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct Person {
	string name;
	string surname;
	string gender;
	int age;
	double height;
	double weight;
};

int main() 
{
	/* inizializza la struct con una lista di inizializzazione */

	Person john = { "John", "Doe", "maschio", 35, 1.85, 80 };

	/* stampa i campi della struct */

	cout << john.name << " " << john.surname << endl << "Sesso: " << john.gender << endl << "età: " << john.age << endl << "altezza: " << john.height << endl << "peso: " << john.weight << endl;

	/* inizializza singolarmente i campi della struct */

	Person fred;
	fred.name = "Fred";
	fred.surname = "Bloggs";
	fred.gender = "male";
	fred.age = 30;
	fred.height = 1.75;
	fred.weight = 70;

	/* stampa i campi della struct */

	cout << fred.name << " " << fred.surname << endl << "Sesso: " << fred.gender << endl << "età: " << fred.age << endl << "altezza: " << fred.height << endl << "peso: " << fred.weight << endl;
}

