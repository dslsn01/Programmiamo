/* file esercizio2.cpp */

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main() 
{
	ifstream file("file.txt");

	if (file) {
		cout << "File aperto con successo." << endl;
	}
}

