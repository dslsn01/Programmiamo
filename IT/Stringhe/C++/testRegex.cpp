/*
file testRegex.cpp
compilare con: g++ -std=c++11 testRegex.cpp
*/

#include <iostream>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::regex_constants::icase;

int main()
{
	// prepara un'espressione regolare

	string r = "^Ul[iy](?:ss|x)es?$";
	regex pattern(r, icase);

	string s[] = {"Ulisse", "ulysse", "Ulysses", "ULIXES"};

	for (string const & name : s) {
		if (regex_match(name, pattern)) {
			cout << "La regex \"" << r << "\" coincide con il nome \"" << name << "\"." << endl;
		}
	}
}

