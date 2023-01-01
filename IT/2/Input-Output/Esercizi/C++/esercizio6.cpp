/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;

int main() 
{
	cout << "Apri il file: ";

	string filename;
	getline(cin, filename);

	ifstream f(filename);
	string s;

	vector<string> lines;

	while (getline(f, s)) {
		lines.push_back(s);
	}

	vector<string>::reverse_iterator it;
	int i = lines.size();

	for (it = lines.rbegin(); it != lines.rend(); ++it) {
		cout << i << " " << (*it) << endl;
		i--;
	}
}

