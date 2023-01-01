/*
file esercizio29.cpp
compilare con: g++ -std=c++11 esercizio29.cpp
*/

#include <iostream>
#include <regex>
#if defined(__APPLE__)
#include <codecvt>
#elif defined(__WIN32)
#include <io.h>
#include <fcntl.h>
#endif

using std::wstring;
using std::wcin;
using std::wcout;
using std::endl;
using std::locale;
using std::wregex;
using std::regex_match;

int main()
{
	setlocale(LC_ALL, "");
#if defined(__APPLE__)
	wcout.imbue(std::locale(locale(""), new std::codecvt_utf8<wchar_t>));
	wcin.imbue(std::locale(locale(""), new std::codecvt_utf8<wchar_t>));
#elif defined(__WIN32)
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
#endif

	wcout << "Scrivi una parola (o una frase): ";

	wstring s;
	getline(wcin, s);

	if (s.empty()) {
		wcout << "Stringa vuota!" << endl;
		return 1;
	}

	locale loc("");
	wstring s1 = regex_replace(s, wregex(L"[^À-ùA-Za-z]"), wstring(L""));

	if (s1.empty()) {
		wcout << "La stringa \"" << s << "\" non contiene caratteri alfabetici!" << endl;
		return 1;
	}

	wcout << "Controllando i caratteri: ";

	int size = s1.size();
	int lcount = 0;
	int ucount = 0;

	for (wchar_t c : s1) {
		if (islower(c, loc)) lcount++;
		else ucount++;
	}

	if (ucount == size) {
		wcout << "   -> la stringa \"" << s << L"\" contiene solo caratteri maiuscoli." << endl;
	}
	else if (lcount == size) {
		wcout << "   -> la stringa \"" << s << L"\" contiene solo caratteri minuscoli." << endl;
	}
	else {
		wcout << "   -> la stringa \"" << s << "\" contiene caratteri maiuscoli e minuscoli." << endl;
	}

	wcout << "Con le espressioni regolari: ";

	if (regex_match(s1, wregex(L"^[^a-zà-ù]+$"))) {
		wcout << "-> la stringa \"" << s << L"\" contiene solo caratteri maiuscoli." << endl;
	}
	else if (regex_match(s1, wregex(L"^[^A-ZÀ-Ù]+$"))) {
		wcout << "-> la stringa \"" << s << L"\" contiene solo caratteri minuscoli." << endl;
	}
	else {
		wcout << "-> la stringa \"" << s << "\" contiene caratteri maiuscoli e minuscoli." << endl;
	}
}

