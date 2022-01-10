/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp
*/

#include <ctime>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

int main()
{
	cout << "Apri il file: ";

	string filename;
	getline(cin, filename);

	fstream f(filename);

	if (f) {
		cout << "#### File esistente aperto in sola lettura. ####" << endl;
		string s;

		while (getline(f, s))
		{
			cout << s << endl;
		}
	}
	else {
		f.open(filename, fstream::out);
		time_t now = time(NULL);
		struct tm *timeinfo = localtime(&now);
		char buffer[80];
		strftime(buffer, sizeof(buffer), "File creato il %d-%m-%Y alle ore %H:%M:%S", timeinfo);

		f << string(buffer) << endl;
	}
}

