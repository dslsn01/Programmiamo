/*
file esercizio15.cpp
compilare con: g++ -std=c++11 esercizio15.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;
using std::greater;

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

	sort(begin(nums), end(nums), greater<int>());

	cout << "[";
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
	cout << "\b\b]" << endl;

	int maxIndex = 0;
	cout << "Numero maggiore nell'array: " << nums[maxIndex] << endl;

	int minIndex = LEN - 1;
	cout << "Numero minore nell'array: " << nums[minIndex] << endl;
}

