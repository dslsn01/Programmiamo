/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>
#include <functional>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;
using std::greater;

int main()
{
	vector<int> nums(10);

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < 10; i++) {
		nums[i] = dist(gen);
	}

	cout << "Vettore originale:" << endl << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	sort(nums.begin(), nums.end(), greater<int>());

	cout << "Vettore ordinato:" << endl  << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int maxIndex = nums.size() - 1;
	cout << "Numero maggiore nel vettore: " << nums[maxIndex] << endl;

	int minIndex = 0;
	cout << "Numero minore nel vettore: " << nums[minIndex] << endl;
}

