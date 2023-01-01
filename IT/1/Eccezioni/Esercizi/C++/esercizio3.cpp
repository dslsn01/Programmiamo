/* file esercizio3.cpp */

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::out_of_range;

int main()
{
	string var = "Cantami, o Diva, del pelide Achille l'ira funesta";

	int i = 0;

	try {
		while (true) {
			cout << var.at(i);
			i++;
		}
	}
	catch (out_of_range& e) {
		cout << endl;
	}

	cout << "Fine del programma." << endl;
}

