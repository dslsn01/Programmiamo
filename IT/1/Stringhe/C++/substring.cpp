/* file substring.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string s = "Ciao, mondo!";

	string s1 = s.substr(0, 6);
	string s2 = s.substr(6, s.size());

	cout << s1 << endl;
	cout << s2 << endl;
}

