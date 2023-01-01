/*
file testUnicode.cpp
compilare con: g++ -std=c++11 testUnicode.cpp
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
	// necessario per il prompt dei comandi di Windows
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);
#endif

	wcout << "\tCaratteri ASCII stampabili (32-127): " << endl << endl;

	int i;
	for (i = 32; i <= 127; i++) {
		// salta il carattere di delete
		if (i == 127) continue;
		wcout << (char) i << " ";
	}

	wcout << endl << endl << "\tCaratteri Unicode stampabili (160-255): " << endl << endl;

	for (i += 32; i <= 255; i++) {
		wprintf(L"%lc ", (wchar_t) i);
	}

	wcout << endl;

	wstring s;
	wcout << "Scrivi _una sola parola_ (no numeri, spazi o punteggiatura: ammessi caratteri accentati): ";
	getline(wcin, s);

	int l = s.size();
	int k = 0;

	for (wchar_t c : s) {
		if (!iswalpha(c)) break;
		k++;
	}

	if (k == l) {
		wcout << "La stringa \"" << s << "\" contiene " << l << " caratteri, per un totale di " << l*sizeof(wchar_t) << " byte." << endl;
	}
	else wcout << "Parola non valida!" << endl;
}

