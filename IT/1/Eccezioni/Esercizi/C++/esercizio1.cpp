/*
file esercizio1.cpp
compilare con: g++ -std=c++11 esercizio1.cpp
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
	array<string, 3> arr = {"rosso", "verde", "blu"};

	int i = 0;

	while (true) {
		try {
			cout << arr.at(i) << endl;
			i++;
		}
		catch (out_of_range& e) {
			break;
		}
	}

	cout << "Fine del programma." << endl;
}

