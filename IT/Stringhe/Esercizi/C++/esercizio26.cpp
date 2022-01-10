/*
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp
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
using std::wcout;

using std::endl;
using std::wregex;
using std::wsregex_iterator;
using std::locale;

int main()
{
	setlocale(LC_ALL, "");
#if defined(__APPLE__)
	wcout.imbue(std::locale(locale(""), new std::codecvt_utf8<wchar_t>));
#elif defined(__WIN32)
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
#endif

	wstring s = L"Nel mezzo del cammin di nostra vita\n";
	s += L"mi ritrovai per una selva oscura\n";
	s += L"chè la retta via era smarrita.";

	wcout << "\"" << s << "\"" << endl;

	// contatore delle righe
	int rCount = 0;

	wregex r(L"([^\r\n]+)");

	wsregex_iterator it(s.begin(), s.end(), r);
	wsregex_iterator rend;

	while (it != rend) {
		rCount++;
		++it;
	}

	// contatore delle parole
	int wCount = 0;

	wregex r2(L"([a-zA-ZÀ-ù']+)");

	it = wsregex_iterator(s.begin(), s.end(), r2);

	while (it != rend) {
		wCount++;
		++it;
	}

	// contatore delle frasi
	int sCount = 0;

	wregex r3(L"(.*[\\.\r\n])");

	it = wsregex_iterator(s.begin(), s.end(), r3);

	while (it != rend) {
		sCount++;
		++it;
	}

	wcout << "Il testo contiene " << rCount << " righe, " << sCount << " frasi, " << wCount << " parole, " << s.size() << " caratteri." << endl;
}

