/*
file esercizio21.cpp
compilare con: g++ -std=c++11 esercizio21.cpp
*/

#include <iostream>
#include <iterator>
#include <unordered_set>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::boolalpha;
using std::unordered_set;

int main()
{
	/* gli insiemi A e B non sono ordinati */

	unordered_set<int> a = {1, 2, 3};
	unordered_set<int> b = {3, 2, 1};

	cout << "A = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "B = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	/* verifica se i due insiemi siano uguali */

	cout << "Gli insiemi A e B sono uguali? " << boolalpha << (a == b) << endl;
}

