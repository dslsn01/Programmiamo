/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

int main()
{
	const int LEN = 10;
	int nums[LEN];

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < LEN; i++) {
		nums[i] = dist(gen);
	}

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	sort(begin(nums), end(nums));

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
	cout << "\b\b]" << endl;

	int maxIndex = LEN - 1;
	cout << "Numero maggiore nell'array: " << nums[maxIndex] << endl;

	int minIndex = 0;
	cout << "Numero minore nell'array: " << nums[minIndex] << endl;
}

