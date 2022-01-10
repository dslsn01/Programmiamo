/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp
*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::vector;

int main()
{
	vector<string> v = {"Nel", "bel", "mezzo", "del", "cammin", "di", "nostra", "vita"};

	string s = accumulate(v.begin(), v.end(), string(), [](string& result, const string& t) {
		return !result.empty() ? result + " " + t : t;
	});

	cout << "[";
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "\"" << s << "\"" << endl;
}

