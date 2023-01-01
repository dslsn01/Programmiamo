/*
file esercizio19.cpp
compilare con: g++ -std=c++11 esercizio19.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <random>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::vector;
using std::map;
using std::make_pair;
using std::pair;
using std::set;
using std::count;
using std::inserter;
using std::max_element;

vector<pair<int, int>> mode(vector<int>& v) {
	map<int, int> freq;
	set<int> s(v.begin(), v.end());

	transform(s.begin(), s.end(), inserter(freq, freq.begin()), [&] (const int i) {
		int c = count(v.begin(), v.end(), i);
		return make_pair(i, c);
	});

	auto max = *max_element(freq.begin(), freq.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.second < p2.second;
	});

	int md = max.second;

	vector<pair<int, int>> fv;
	copy_if(freq.begin(), freq.end(), back_inserter(fv), [&](const pair<int, int>& p) {
		return p.second == md;
	});

	return fv;
}

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> rrange(1, 20);

	vector<int> v(rrange(gen)*5);

	uniform_int_distribution<int> dist(1, 100);
	generate(v.begin(), v.end(), bind(dist, ref(gen)));

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	// valori con relativa frequenza

	vector<pair<int, int>> fv = mode(v);

	int md = fv[0].second;

	if (md == 1) {
		cout << "Il vettore non ha una moda." << endl;
		return 0;
	}

	// stampa la moda

	cout << "Moda (" << md << " occorrenze): ";

	for_each(fv.begin(), fv.end(), [](const pair<int, int>& p) {
		cout << p.first << ", ";
	});

	cout << "\b\b " << endl;
}

