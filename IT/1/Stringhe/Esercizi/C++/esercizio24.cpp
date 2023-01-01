/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp
*/

#include <iostream>
#include <regex>

using std::wcout;
using std::wcin;
using std::endl;
using std::wstring;
using std::wregex;

int main()
{
	setlocale(LC_ALL, "");

	wcout << "********************* Cambia la password *********************" << endl;
	wcout << "La password deve contenere un minimo di otto caratteri, inclusa una maiuscola, un numero e un simbolo speciale." << endl;
	wstring pwd;

	wregex r(L"^(.{0,7}|[^\\d]*|[^a-zà-ù]*|[^A-ZÀ-Ù]*|[a-zA-ZÀ-ù0-9]*)$");

	while (pwd.empty()) {
		wcout << "Digita la nuova password: ";
		wstring s;
		getline(wcin, s);

		if (!regex_match(s, r)) {
			pwd = s;
			wcout << "Nuova password salvata." << endl;
		}
		else {
			wcout << "Password non valida!" << endl;
		}
	}
}

