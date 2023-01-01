/*
file esercizio2.cpp
compilare con: g++ -std=c++11 esercizio2.cpp
*/

#include <iostream>
#include <array>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::array;
using std::out_of_range;

int main()
{
	array<string, 4> arr = {"United", "States", "", "America"};

	for (const string &s : arr) {
		try {
			cout << s.at(0);
		}
		catch (out_of_range& e) {}
	}

	cout << endl;
	cout << "Fine del programma." << endl;
}

