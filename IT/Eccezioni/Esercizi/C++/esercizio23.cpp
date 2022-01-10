/* file esercizio23.cpp */

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::logic_error;

int main()
{
	string user;

	while (user.empty()) {
		try {
			cout << "Scrivi il tuo nome: ";
			getline(cin, user);

			if (user.empty()) {
				throw logic_error("Nome non valido!");
			}

			cout << "Ciao, " << user << "!" << endl;
		}
		catch (logic_error& e) {
			cerr << e.what() << endl;
		}
	}

	cout << "Fine del programma." << endl;
}

