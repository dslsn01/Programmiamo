/* file ptrArit2.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	/* dichiara un array di caratteri */

	char arr1[] = {'C','i','a','o','!'};

	/* stampa la dimensione del tipo char e dell'array 'hello' */

	cout << "Dimensione del tipo 'char': " << sizeof(char) << " byte." << endl;
	cout << "Dimensione dell'array di caratteri: " << sizeof(arr1) << " byte." << endl;

	for (int i = 0; i < sizeof(arr1)/sizeof(char); i++) {
		cout << *(arr1 + i);
	}

	cout << endl;

	/* dichiara un array di interi */

	int arr2[] = {1, 2, 3, 4, 5};

	/* stampa la dimensione del tipo int e dell'array 'numbers' */

	cout << "Dimensione del tipo 'int': " << sizeof(int) << " byte." << endl;
	cout << "Dimensione dell'array di interi: " << sizeof(arr2) << " byte." << endl;

	for (int i = 0; i < sizeof(arr2)/sizeof(int); i++) {
		cout << *(arr2 + i) << " ";
	}

	cout << endl;
}

