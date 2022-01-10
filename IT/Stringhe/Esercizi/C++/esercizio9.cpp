/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp
*/

#include <iostream>
#include <sstream>

using std::wstring;
using std::wcout;
using std::endl;
using std::locale;

bool strEq(const wstring& s1, const wstring& s2, const locale& loc) {
	int l = s1.size();
	if (l != s2.size()) return false;

	for (int i = 0; i < l; i++) {
		wchar_t c = s1[i];
		wchar_t c2 = s2[i];

		if (c != c2 && tolower(c, loc) != tolower(c2, loc)) {
			return false;
		}
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "");
	locale loc("");

	wstring s = L"prìncipi";
	wstring ss[] = {L"Prìncipi", L"princìpi"};

	for (auto& t : ss) {
		if (strEq(s, t, loc)) {
			wcout << "Le parole \"" << s << "\" e \"" << t << "\" sono uguali." << endl;
		}
		else {
			wcout << "Le parole \"" << s << "\" e \"" << t << "\" sono diverse." << endl;
		}
	}
}

