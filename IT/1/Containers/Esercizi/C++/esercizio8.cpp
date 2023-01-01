/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp
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
	vector<int> nums(10);

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < 10; i++) {
		nums[i] = dist(gen);
	}

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	int m = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		int n = nums[i];
		if (n < m) m = n;
	}

	cout << "Numero minore nel vettore: " << m << endl;
}

