/*
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp
*/

#include <iostream>
#include <iterator>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream_iterator;
using std::stoi;
using std::unique_ptr;

// distruttore personalizzato: necessario per gli array fino al C++17

void dtor(int *arr) {
	cout << "Libero la memoria." << endl;
	delete []arr;
}

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

	// smart pointer che punta a un array di interi tutti uguali a zero
	unique_ptr<int[], void(*)(int*)> arr(new int[LEN](), dtor);

	cout << "[";
	copy(arr.get(), arr.get()+LEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

