/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp
*/

#include <iostream>
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

	/* analizza i caratteri uno per uno */

	int sz = s.size();
	int ch = 0;
	int num = 0;
	int sp = 0;

	for (wchar_t c : s) {
		if (iswalpha(c)) ch++;
		else if (iswdigit(c)) num++;
		else sp++;
	}

	wcout << "La stringa \"" << s << + "\" (" << sz << " caratteri totali) contiene " << ch << " lettere, " << num << " numeri e " << sp << " simboli." << endl;
}

