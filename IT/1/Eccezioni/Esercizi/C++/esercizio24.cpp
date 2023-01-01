/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
*/

#include <iostream>
#include <chrono>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::chrono::system_clock;
using std::time_t;
using std::localtime;
using std::invalid_argument;
using std::logic_error;

int main()
{
	bool checked = false;
	string user;
	int age = -1;

	while (checked == false) {
		try {
			if (user.empty()){
				cout << "Scrivi il tuo nome: ";
				getline(cin, user);

				if (user.empty()) {
					throw logic_error("Nome non valido!");
				}
			}

			if (age < 0) {
				cout << "Il tuo anno di nascita: ";

				string s;
				getline(cin, s);

				int year = stoi(s);

				auto now = system_clock::now();
				time_t time = system_clock::to_time_t(now);
				struct tm *tm_data = localtime(&time);

				int currYear = 1900 + tm_data->tm_year;

				if (year <= 0 || year > currYear) {
					throw logic_error("Anno di nascita non valido!");
				}

				age = currYear - year;
			}

			cout << "Ciao, " << user << "! Hai " << age << " anni." << endl;

			checked = true;
		}
		catch (invalid_argument &e) {
			cerr << e.what() << endl;
		}
		catch (logic_error& e) {
			cerr << e.what() << endl;
		}
	}

	cout << "Fine del programma." << endl;
}

