/* file stringSearch.cpp */

#include <iostream>

using std::cout; 
using std::endl; 
using std::string; 

int main() 
{
	string s = "Cantami, o Diva, del pelide Achille l'ira funesta"; 
	 
	int indexA = s.find('A');
	cout << "Indice di 'A': " << indexA << endl;

	int indexZ = s.find('Z');
	cout << "Indice di 'Z': " << indexZ << endl; 

	int indexAchille = s.find("Achille");
	cout << "Indice della parola 'Achille': " << indexAchille << endl; 
}

