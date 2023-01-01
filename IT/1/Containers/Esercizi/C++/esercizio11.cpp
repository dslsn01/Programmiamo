/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::boolalpha;
using std::sort;

int main()
{
	vector<int> a = {1, 2, 3};
	vector<int> b = {3, 2, 1};

	cout << "a = [";
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "b = [";
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	vector<int> copy1 = a;
	vector<int> copy2 = b;

	sort(copy1.begin(), copy1.end());
	sort(copy2.begin(), copy2.end());

	cout << "a e b contengono gli stessi elementi? " << boolalpha << (copy1 == copy2) << endl;
}

