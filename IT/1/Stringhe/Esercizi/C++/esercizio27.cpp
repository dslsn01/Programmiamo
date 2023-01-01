/*
file esercizio27.cpp
compilare con: g++ -std=c++11 esercizio27.cpp
*/

#include <iostream>
#include <algorithm>
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
using std::find;
using std::begin;
using std::end;
using std::wregex;
using std::regex_constants::icase;
using std::wsregex_iterator;

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

	wcout << "Controllando i caratteri: ";

	wchar_t voc [] = {'a', L'à', 'e', L'è', 'i', L'ì', 'o', L'ò', 'u', L'ù'};
	int v = 0;

	locale loc("");

	for (wchar_t c : s) {
		if (find(begin(voc), end(voc), tolower(c, loc)) != end(voc)) v++;
	}

	wcout << "   -> la stringa \"" << s << "\" contiene " << v << " vocali." << endl;

	wcout << "Con le espressioni regolari: ";

	wregex r(L"[À-ùaeiou]", icase);
	v = 0;

	wsregex_iterator it(s.begin(), s.end(), r);
	wsregex_iterator rend;

	while (it != rend) {
		v++;
		++it;
	}

	wcout << "-> la stringa \"" << s << "\" contiene " << v << " vocali." << endl;
}

