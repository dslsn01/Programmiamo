/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	cout << "Un semplice editor di testo\nPremi \"Ctrl+C\" (su Windows) o \"Ctrl+D\" (Linux e MacOS) per finire di scrivere." << endl << endl;

	string text;
	string line;

	while (!getline(cin, line).eof()) {
		text += line + "\n";
	}

	cin.clear();

	bool quit = false;

	while (!quit) {
		cout << "Digita \"s\" per salvare su file, \"q\" per uscire senza salvare: ";

		string buff;
		getline(cin, buff);

		if (buff.size() > 1) continue;

		char opt = tolower(buff[0]);

		if (opt == 's') {
			string filename;
			bool save = false;
			while (!save) {
				cout << "Salva con nome: ";
				getline(cin, filename);

				if (ifstream(filename)) {
					cout << "Il file " << filename << " esiste. Sovrascriverlo? \"y\" - sì, \"n\" - no: ";

					string buff;
					getline(cin, buff);

					if (buff.size() == 1) {
						char ow = tolower(buff[0]);
						if (ow == 'y') save = true;
					}
				}
				else {
					save = true;
				}
			}

			ofstream doc(filename);
			doc << text;

			cout << "File \"" << filename << "\" salvato su disco." << endl;
			quit = true;
		}
		else if (opt == 'q') {
			quit = true;
		}
	}
}

