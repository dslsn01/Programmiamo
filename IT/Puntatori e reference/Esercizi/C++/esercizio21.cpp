/*
file esercizio21.cpp
compilare con: g++ -std=c++11 esercizio21.cpp
*/

#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream_iterator;

int main()
{
	cout << "Numero di elementi dell'array: ";

	string s;
	getline(cin, s);

	if (s.empty() ||
		s.find_first_not_of("0123456789") != string::npos ||
		stoi(s) == 0)
	{
		cout << "Numero non valido!" << endl;
		return -1;
	}

	const int LEN = stoi(s);

	// un array di tot elementi, tutti uguali a zero

	int* arr = new int[LEN]();

	cout << "[";
	copy(arr, arr+LEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	delete [] arr;
}

