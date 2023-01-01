/* file helloString.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	/* dichiara una stringa di caratteri */

	string s = "Ciao, mondo!";

	/* stampa la stringa sulla console, carattere per carattere */

	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
	}

	/* aggiunge un'interruzione di riga */

	cout << endl;
}

