/* file ptrArit.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	char arr[] = {'C','i','a','o', ' ', 'm', 'o', 'n', 'd', 'o', '!'};

	/* legge il contenuto dell'array con un ciclo for standard */ 

	for (int i = 0; i < sizeof(arr)/sizeof(char); i++) { 
		cout << arr[i];
	} 

	cout << endl;

	/* il nome dell'array è già un puntatore: si può utilizzare l'aritmetica dei puntatori */

	for (int i = 0; i < sizeof(arr)/sizeof(char); i++) {
		cout << *(arr + i); 
	}

	cout << endl;
}

