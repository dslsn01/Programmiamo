/*
file esercizio21.cpp
compilare con: g++ -std=c++11 esercizio21.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ostream_iterator;
using std::stoi;
using std::copy;
using std::find;
using std::invalid_argument;
using std::logic_error;

int main()
{
	try
	{
		cout << "Quanti animali vuoi inserire? ";

		string s;
		getline(cin, s);
		const int SIZE = stoi(s);

		if (SIZE < 1) return -1;

		string *animals = new string[SIZE];
		int i = 0;

		while (i < SIZE) {
			cout << "Scrivi un nuovo animale: ";

			try {
				string animal;
				getline(cin, animal);

				transform(animal.begin(), animal.end(), animal.begin(), ::tolower);

				if (animal.empty()) {
					throw logic_error("Nome non valido!");
				}
				if (find(animals, animals+SIZE, animal) != animals+SIZE) {
					throw logic_error("Animale già presente!");
				}

				animals[i] = animal;
				i++;
			}
			catch (logic_error& e) {
				cerr << e.what() << endl;
			}
		}

		string animal;

		while (animal.empty()) {
			try {
				cout << "Recupera l'animale con indice: ";

				string pos;
				getline(cin, pos);
				int index = stoi(pos);

				if (index < 0 || index > SIZE-1) {
					throw logic_error("Animale non presente nella lista!");
				}

				animal = animals[index];
				cout << animal << endl;
			}
			catch (logic_error& e) {
				cerr << e.what() << endl;
			}
		}

		delete [] animals;
	}
	catch (invalid_argument &e) {
		cerr << e.what() << endl;
	}

	cout << "Fine del programma." << endl;
}

