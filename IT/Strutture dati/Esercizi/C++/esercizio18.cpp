/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp
*/

#include <iostream>
#include <iterator>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::ostream_iterator;
using std::boolalpha;

int main()
{
	array<int, 3> a = {1, 2, 3};
	array<int, 3> b = {3, 2, 1};
	array<int, 3> c = {1, 2, 3};

	cout << "a = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "b = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "c = [";
	copy(c.begin(), c.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "a e b sono uguali? " << boolalpha << (a == b) << endl;
	cout << "a e c sono uguali? " << boolalpha << (a == c) << endl;
}

