/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp
*/

#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::isupper;

int main()
{
	string n[] = {"United States of America", "Unione delle Repubbliche Socialiste Sovietiche", "European Union"};

	for (string& s : n) {
		string acr = "";
		istringstream iss(s);
		string t;

		while (getline(iss, t, ' '))
		{
			char i = t[0];
			if (isupper(i)) {
				acr += i;
				acr.append(".");
			}
		}

		cout << acr << " (" << s << ")" << endl;
	}
}

