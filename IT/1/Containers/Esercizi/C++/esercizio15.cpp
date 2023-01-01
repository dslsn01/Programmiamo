/*
file esercizio15.cpp
compilare con: g++ -std=c++11 esercizio15.cpp
*/

#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::pair;
using std::unordered_map;
using std::vector;
using std::sort;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second > p2.second;
}

int main()
{
	vector<int> nums;

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < 100; i++) {
		nums.push_back(dist(gen));
	}

	cout << "[";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	unordered_map<int, int> occurrences;

	for (auto& n : nums) {
		occurrences[n]++;
	}

	vector<pair<int, int>> counts(occurrences.begin(), occurrences.end());
	sort(counts.begin(), counts.end(), comp);

	int md = counts[0].second;

	if (md == 1) {
		cout << "Il vettore non ha una moda." << endl;
		return 0;
	}

	cout << "Moda (" << md << " occorrenze): ";

	int j = 0;
	for (auto& p : counts) {
		if (p.second == md) {
			if (j > 0) cout << ", ";
			cout << p.first;
			j++;
		}
	}

	cout << "." << endl;
}

