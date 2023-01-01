/* file writeFile.cpp */

#include <iostream>
#include <fstream>

using std::ofstream;
using std::endl;

int main()
{
	/* apre il file */

	ofstream file1("helloworld.txt");

	/* scrive nel file la frase "Ciao, mondo!" */

	file1 << "Ciao, mondo!" << endl;

	/* chiude il file e salva le modifiche */

	file1.close();
}

