/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main()
{
	unordered_map<string, string> messages = {{"it", "Benvenuto!"}, {"en", "Welcome!"}, {"en-us", "Welcome!"}};

	cout << "Seleziona la tua lingua: ";

	string lang;
	getline(cin, lang);

	if (messages.find(lang) != messages.end()) {
		cout << messages[lang] << endl;
	}
	else {
		if (lang.empty()) {
			cout << messages["en"] << endl;
			return 0;
		}

		cout << "Lingua sconosciuta!" << endl << "Aggiungere nuova lingua? s/n: ";
		string s;
		getline(cin, s);

		if (s == "s") {
			cout << "Nuovo messaggio di benvenuto: ";
			string msg;
			getline(cin, msg);
			messages[lang] = msg;

			cout << messages[lang] << endl;

			cout << "Messaggi di benvenuto aggiornati." << endl;

			for (auto& msg : messages) {
				cout << msg.first << "=" << msg.second << endl;
			}
		}
	}
}

