/*
file esercizio.cpp
compilare con: g++ -std=c++11 esercizio.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::max_element;
using std::min_element;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second < p2.second;
}

int main()
{
	unordered_map<int, int> nums = {{1, 7}, {2, 5}, {3, 3}};

	cout << "Numeri = {";

	for (auto& pair : nums) {
		cout << pair.first << "=" << pair.second << ", ";
	}

	cout << "\b\b}" << endl;

	pair<int, int> max = *max_element(nums.begin(), nums.end(), comp);
	pair<int, int> min = *min_element(nums.begin(), nums.end(), comp);

	cout << "Maggior valore nella mappa: " << max.second << ", associato alla chiave " << max.first << "." << endl;
	cout << "Minor valore nella mappa: " << min.second << ", associato alla chiave " << min.first << "." << endl;
}

