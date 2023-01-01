/*
file esercizio27.cpp
compilare con: g++ -std=c++11 esercizio27.cpp
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

int main()
{
	unordered_map<int, int> nums = {{1, 7}, {2, 5}, {3, 3}};

	cout << "Numeri = {";

	for (auto& pair : nums) {
		cout << pair.first << "=" << pair.second << ", ";
	}

	cout << "\b\b}" << endl;

	pair<int, int> max = *max_element(nums.begin(), nums.end());
	pair<int, int> min = *min_element(nums.begin(), nums.end());

	cout << "Chiave maggiore nella mappa: " << max.first << ", associata al valore " << max.second << "." << endl;
	cout << "Chiave minore nella mappa: " << min.first << ", associata al valore " << min.second << "." << endl;
}

