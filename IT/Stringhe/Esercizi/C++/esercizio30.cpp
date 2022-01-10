/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <regex>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::regex;
using std::numeric_limits;
using std::regex_constants::icase;

int main()
{
	cout << "Programmiamo un client di posta elettronica." << endl;

	// destinatario
	string dest = "";

	// oggetto
	string obj = "";

	// corpo della mail
	string body = "";

	// eventuale allegato
	string att = "";

	bool exit = false;

	cout << "From: joebloggs@programmiamo.com" << endl;

	regex mailPattern("[\w\.]+@[\w]+\.[\w]{2,}");
	regex attPattern("alleg(at)?o", icase);

	while (!exit) {
		if (dest.empty()) {
			cout << "To: ";
			string _dest;
			getline(cin, _dest);
			if (!regex_match(_dest, mailPattern)) continue;
			dest = _dest;
		}

		if (obj.empty()) {
			cout << "Oggetto: ";
			string _obj;
			getline(cin, _obj);
			obj = !_obj.empty() ? _obj : " ";
		}

		if (body.empty()) {
			cout << "------- Messaggio -------" << endl << endl;
			string _body;
			string line;

			// si chiude con CTRL+D
			while (!getline(cin, line).eof()) {
				_body += line + "\n";
			}

			cin.clear();

			body = !_body.empty() ? _body : " ";
			cout << endl << "-------------------------" << endl;
		}

		cout << "\"y\" - invia la mail" << endl << "\"a\" - aggiungi un allegato" << endl << "\"q\" - esci" << endl;
		string buf1;
		getline(cin, buf1);
		if (buf1.size() > 1) continue;
		char opt = !buf1.empty() ? tolower(buf1[0]) : numeric_limits<char>::min();

		if (opt == 'y') {
			if (att.empty()) {
				if (regex_search(obj, attPattern) || regex_search(body, attPattern)) {
					cout << "Forse vuoi allegare qualcosa. Inviare?" << endl << "\"s\" - invia senza allegati" << endl << "\"n\" - torna alla mail" << endl;
					string buf2;
					getline(cin, buf2);
					char c = !buf2.empty() ? tolower(buf2[0]) : numeric_limits<char>::min();
					if (c != 's') continue;
				}
			}

			cout << "Messaggio inviato." << endl;
		}
		else if (opt == 'a') {
			cout << "File da allegare: ";
			string _att;
			getline(cin, _att);

			if (_att.empty()) continue;
			att = _att;
			cout << endl << "Caricamento di \"" << att << "\"..." << endl;
			cout << "####### 100% completato #######" << endl;
			continue;
		}

		exit = true;
	}
}

