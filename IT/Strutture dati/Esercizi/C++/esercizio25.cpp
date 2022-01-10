/*
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp
*/

#include <iostream>
#include <iterator>
#include <random>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

int main()
{
	const int LEN = 10;
	int nums[LEN];

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 10);

	for (int i = 0; i < LEN; i++) {
		int r = dist(gen);
		nums[i] = r;
	}

	cout << "Array originale: " << endl << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	bool dupl[LEN];
	int d = 0;

	for (int i = 0; i < LEN; i++) {
		for (int j = i+1; j < LEN; j++) {
			// duplicato trovato per la prima volta
			if (nums[i] == nums[j] && !dupl[j]) {
				dupl[j] = true;
				d++;
			}
		}
	}

	const int ULEN = LEN-d;
	int uniques[ULEN];
	for (int i = 0, j = 0; i < LEN; i++) {
		if (dupl[i] == false) {
			uniques[j] = nums[i];
			j++;
		}
	}

	cout << "Array senza elementi duplicati: " << endl << "[";
	copy(uniques, uniques + ULEN, ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

