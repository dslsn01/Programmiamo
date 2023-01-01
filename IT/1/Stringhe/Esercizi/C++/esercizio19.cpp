/* file esercizio19.cpp */

#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::replace;

int main()
{
	// formato SI
	string si = "1 234 567.89";

	// formato USA
	string us = si;

	replace(us.begin(), us.end(), ' ', ',');

	// formato italiano
	string it = si;

	replace(it.begin(), it.end(), '.', ',');
	replace(it.begin(), it.end(), ' ', '.');

	cout << "Stile SI: " << si << endl;
	cout << "Stile US: " << us << endl;
	cout << "Stile IT: " << it << endl;
}

