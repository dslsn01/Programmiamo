/* file esercizio.cpp */

#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::remove_if;

int main()
{
	string s = "Era pacifica pare";

	string s1 = s;
	s1.erase(remove_if(s1.begin(), s1.end(), isspace), s1.end());
	int l = s1.size();

	int o1 = l / 2;
	int o2 = l % 2 == 0 ? o1 : o1 + 1;

	string t1 = s1.substr(0, o1);
	string t2 = s1.substr(o2, l);
	reverse(t2.begin(), t2.end());

	bool pal = true;

	for (int i = 0; i < t1.size(); i++) {
		char c1 = t1[0];
		char c2 = t2[0];

		if (c1 != c2) {
			if (tolower(c1) != tolower(c2)) {
				pal = false;
				break;
			}
		}
	}

	if (pal == true) {
		cout << "La frase \"" << s << "\" è palindroma." << endl;
	}
}

