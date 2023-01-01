/* file esercizio1.cpp */

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main()
{
	if (ifstream("file.txt")) {
		cout << "Il file esiste." << endl;
	}
	else {
		cout << "Il file non esiste!" << endl;
	}
}

