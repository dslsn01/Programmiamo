/* file esercizio17.cpp */

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

	wstring result;

	locale loc("");

	for (int i = 0; i < s.size(); i++) {
		wchar_t c = s[i];
		if (i % 2 == 0) {
			if (islower(c, loc)) {
				c = toupper(c, loc);
			}
		}
		else {
			if (isupper(c, loc)) {
				c = tolower(c, loc);
			}
		}

		result += c;
	}

	wcout << result << endl;
}

