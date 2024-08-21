/*
file esercizio16.cpp
compilare con: g++ -std=c++20 esercizio16.cpp
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ranges>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;

int main()
{
	vector<int> v1 = {1, 2, 3, 4};
	vector<int> v2 = {5, 6, 7};
	vector<int> v3 = {8, 9};
	vector<int> v4 = {10};

	vector<vector<int>> v = {v1, v2, v3, v4};

	cout << "[";

	for_each(v.begin(), v.end(), [](const vector<int>& v) {
		cout << "[";
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
		cout << "\b\b], ";
	});

	cout << "\b\b]" << endl;

	auto flat = std::ranges::join_view(v);

	cout << "[";
	copy(flat.begin(), flat.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;
}

