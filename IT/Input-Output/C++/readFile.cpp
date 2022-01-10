/* file readFile.cpp */

#include <iostream>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;

int main()
{
	/* apre il file */

	ifstream file1("helloworld.txt");

	string s;

	/* stampa il contenuto del file */

	while (file1.good())
	{
		getline(file1, s);
		cout << s;
	}

	cout << endl;

	/* chiude il file */

	file1.close();
}

