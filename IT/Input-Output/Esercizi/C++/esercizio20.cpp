/*
file esercizio20.cpp
compilare con: g++ -std=c++11 esercizio20.cpp
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::transform;

int main()
{
	cout << "File da copiare: ";
	string filename;
	getline(cin, filename);

	ifstream doc(filename);

	if (doc) {
		cout << "Nome file di backup: ";
		string bakName;
		getline(cin, bakName);

		if (ifstream(bakName)) {
			cout << "Il file \"" << bakName << "\" esiste. Sovrascriverlo? s | n: ";

			string opt;
			getline(cin, opt);
			transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

			if (opt != "s") {
				cout << "File \"" << bakName << "\" ignorato." << endl;
				return 0;
			}
		}

		ofstream backup(bakName);

		string s;
		while (getline(doc, s)) {
			backup << s << endl;
		}

		cout << "File \"" << bakName << "\" salvato su disco." << endl;
	}
}

