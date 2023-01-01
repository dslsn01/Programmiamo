/*
file esercizio13.cpp
compilare con: g++ -std=c++11 esercizio13.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main() {
	vector<int> v(100);
	iota(v.begin(), v.end(), 1);

	int tot = accumulate(v.begin(), v.end(), 0);

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Somma dei numeri nel vettore: " << tot << endl;
}

