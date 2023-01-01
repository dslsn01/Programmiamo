/* file esercizio18.cpp */

#include <iostream>
#include <algorithm>
#if defined(__APPLE__)
#include <codecvt>
#elif defined(__WIN32)
#include <io.h>
#include <fcntl.h>
#endif

using std::wstring;
using std::wcout;
using std::endl;
using std::locale;
using std::replace;

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

	wstring s = L"David Bowman: 'Hal, apri la saracinesca esterna! Pronto Hal, mi ricevi? Pronto Hal, mi ricevi?'\n";
	s += L"HAL 9000: 'Affermativo, David. Ti ricevo'.\n";
	s += L"David Bowman: 'Apri la saracinesca esterna, Hal'.\n";
	s += L"HAL 9000: 'Mi dispiace David, purtroppo non posso farlo'.\n";
	s += L"David Bowman: 'Qual è il motivo?'\n";
	s += L"HAL 9000: 'Credo che tu lo sappia altrettanto bene quanto me'.";

	wcout << s << endl;

	wcout << endl << "-> Sostituiamo i singoli apici con i doppi apici." << endl << endl;

	replace(s.begin(), s.end(), '\'', '"');

	wcout << s << endl;

	// locale loc("");
}

