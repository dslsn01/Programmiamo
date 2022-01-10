/*
file esercizio15.cpp
compilare con: g++ -std=c++11 esercizio15.cpp
*/

#include <iostream>
#include <algorithm>
#include <vector>
// necessario con gcc 10.x
#include <numeric>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

int main()
{
	vector<int> v(10);
	iota(v.begin(), v.end(), 1);

	string s = accumulate(v.begin(), v.end(), string(), [] (string& result, const int& b) {
		return !result.empty() ? result + ", " + to_string(b) : to_string(b);
	});

	cout << s << endl;
}

