/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp
*/

#include <ctime>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

int main()
{
	cout << "Apri il file: ";

	string filename;
	getline(cin, filename);

	ofstream f(filename);

	time_t now = time(NULL);
	struct tm *timeinfo = localtime(&now);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "File creato il %d-%m-%Y alle ore %H:%M:%S", timeinfo)\
;

	f << string(buffer) << endl;
}

