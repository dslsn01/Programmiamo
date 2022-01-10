/* file copyFile.cpp */

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	/* apre il primo file */

	ifstream file1("helloworld.txt");

	/* apre il secondo file */

	ofstream file2("helloworld2.txt");
	string s;
	
	/* copia il contenuto del primo file nel secondo */

	while (file1.good()) 
	{
		getline(file1, s);
		file2 << s;
	}

	/* chiude entrambi i file */

	file2.close();
	file1.close();
}

