/*
file esercizio17.cpp
compilare con: g++ -std=c++11 esercizio17.cpp
*/

#include <iostream>
#include <iterator>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;
using std::array;
using std::ostream_iterator;
using std::boolalpha;
using std::sort;

int main()
{
	array<int, 3> a = {1, 2, 3};
	array<int, 3> b = {3, 2, 1};

	cout << "a = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "b = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	array<int, 3> copy1 = a;
	array<int, 3> copy2 = b;

	sort(copy1.begin(), copy1.end());
	sort(copy2.begin(), copy2.end());

	cout << "a e b contengono gli stessi elementi? " << boolalpha << (copy1 == copy2) << endl;
}

