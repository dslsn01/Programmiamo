/* 
file sorting.cpp
compilare con: g++ -std=c++11 sorting.cpp
*/

#include <iostream>
#include <random>
#include <iterator>
#include <list>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::list;

int main()
{
	/* crea una lista di numeri interi */

	list<int> li;

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < 10; i++) {
		int n = dist(gen);
		li.push_back(n);
	}

	cout << "Lista originale:" << endl << "[";
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	li.sort();

	cout << "Lista ordinata:" << endl << "[";
	copy(li.begin(), li.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

