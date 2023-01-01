/*
file esercizio4.cpp
compilare con: g++ -std=c++11 esercizio4.cpp
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::array;
using std::invalid_argument;
using std::ostream_iterator;

int main()
{
	array<string, 7> nums = {"1", "2", "", "3", "abc", "7", "def"};
	copy(nums.begin(), nums.end(), ostream_iterator<string>(cout, " "));
	cout << endl;

	int tot = 0;

	try {
		for (const auto &n : nums) {
			tot += stoi(n);
		}
	}
	catch (invalid_argument& e) {
		cerr << e.what() << endl;
	}

	cout << "Somma dei numeri presenti: " << tot << endl;
	cout << "Fine del programma." << endl;
}

