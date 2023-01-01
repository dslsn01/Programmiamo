/*
file esercizio7.cpp
compilare con: g++ -std=c++11 esercizio7.cpp
*/

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::find;

int main()
{
	string s = "3.14159";

	auto delim = s.find(".");
	string t1 = s.substr(0, delim);
	string t2 = s.substr(delim+1, s.size());

	cout << "La parte intera di " << s << " è " << t1 << ", mentre la parte decimale è 0." << t2 << "." << endl;
}

