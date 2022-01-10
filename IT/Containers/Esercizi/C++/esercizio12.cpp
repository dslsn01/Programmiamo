/*
file esercizio12.cpp
compilare con: g++ -std=c++11 esercizio12.cpp
*/

#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::boolalpha;

int main()
{
	vector<int> a = {1, 2, 3};
	vector<int> b = {3, 2, 1};
	vector<int> c = {1, 2, 3};

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

