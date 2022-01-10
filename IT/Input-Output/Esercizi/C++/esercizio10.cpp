/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp
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

	time_t now = time(NULL);
	struct tm *timeinfo = localtime(&now);
	char buffer[80];

	if (f) {
		f.close();
		f.open(filename, fstream::out | fstream::app);
		strftime(buffer, sizeof(buffer), "File modificato il %d-%m-%Y alle ore %H:%M:%S", timeinfo);

		f << string(buffer) << endl;
	}
	else {
		f.open(filename, fstream::out);
		strftime(buffer, sizeof(buffer), "File creato il %d-%m-%Y alle ore %H:%M:%S", timeinfo);

		f << string(buffer) << endl;
	}
}

