/*
file esercizio21.cpp
compilare con: g++ -std=c++11 esercizio21.cpp
*/

#include <iostream>
#include <regex>

using std::string;
using std::cout;
using std::endl;
using std::regex;
using std::regex_replace;

int main()
{
	string s = "Il rosso e il nero";

	regex r("Il ([a-zA-Z]+) e il ([a-zA-Z]+)");

	string s2 = regex_replace(s, r, "Il $2 e il $1");

	cout << s << endl;
	cout << s2 << endl;
}

