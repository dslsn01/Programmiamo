/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::vector;

vector<int> merge(vector<int>& l, vector<int>& r) {
	if (l.empty()) return r;
	if (r.empty()) return l;

	if (l[0] > r[0]) {
		vector<int> r2(r.begin()+1, r.end());
		vector<int> cons = merge(l, r2);
		vector<int> result = {r[0]};
		result.insert(result.end(), cons.begin(), cons.end());
		return result;
	}
	else {
		vector<int> l2(l.begin()+1, l.end());
		vector<int> cons = merge(l2, r);
		vector<int> result = {l[0]};
		result.insert(result.end(), cons.begin(), cons.end());
		return result;
	}
}

std::vector<int> mergesort(vector<int>& v) {
	if (v.size() <= 1) return v;
	int mid = v.size() / 2;
	vector<int> lt(v.begin(), v.begin()+mid);
	vector<int> rt(v.begin()+mid, v.end());
	vector<int> l = mergesort(lt);
	vector<int> r = mergesort(rt);
	return merge(l, r);
}

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	vector<int> v(25);
	generate(v.begin(), v.end(), [&] () { return dist(gen); });

	vector<int> v2 = mergesort(v);

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "[";
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

