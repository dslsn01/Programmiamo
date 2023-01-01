/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <unordered_set>
#include <list>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::list;
using std::unordered_set;

int main()
{
	list<int> nums;

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 10);

	for (int i = 0; i < 10; i++) {
		int r = dist(gen);
		nums.push_back(r);
	}

	cout << "Vettore originale: " << endl << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	unordered_set<int> uniques(nums.begin(), nums.end());

	cout << "Vettore senza elementi duplicati: " << endl << "[";
	copy(uniques.begin(), uniques.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

