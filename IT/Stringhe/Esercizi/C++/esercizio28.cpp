/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
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
using std::regex_replace;
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
	int cons = 0;

	locale loc("");

	for (wchar_t c : s) {
		// salta punteggiatura, spazi, simboli speciali...
		if (!iswalpha(c)) continue;
		if (find(begin(voc), end(voc), tolower(c, loc)) == end(voc)) cons++;
	}

	wcout << "   -> la stringa \"" << s << "\" contiene " << cons << " consonanti." << endl;

	wcout << "Con le espressioni regolari: ";

	cons = 0;

	// elimina punteggiatura, spazi, simboli speciali...

	wregex nl(L"[^À-ùa-zA-Z]");
	wstring st;
	st = regex_replace(s, nl, wstring(L""));

	if (!st.empty()) {
		// [^aeiouÀ-ù] // <- questa non funziona: indagare
		// esclude tutto ciò che non è una vocale
		wregex r(L"[^À-ùaeiou]", icase);

		wsregex_iterator it(st.begin(), st.end(), r);
		wsregex_iterator rend;

		while (it != rend) {
			cons++;
			++it;
		}
	}

	wcout << "-> la stringa \"" << s << "\" contiene " << cons << " consonanti." << endl;
}

