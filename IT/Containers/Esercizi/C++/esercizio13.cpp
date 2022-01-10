/*
file esercizio13.cpp
compilare con: g++ -std=c++11 esercizio13.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

int main()
{
	vector<int> nums;
	nums.reserve(20);

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < 20; i++) {
		nums.push_back(dist(gen));
	}

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	vector<int> p; 	// numeri pari
	vector<int> dp; // numeri dispari

	for (int n : nums) {
		if (n % 2 == 0) p.push_back(n);
		else dp.push_back(n);
	}

	cout << "Numeri pari:" << endl << "[";
	copy(p.begin(), p.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Numeri dispari:" << endl << "[";
	copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

