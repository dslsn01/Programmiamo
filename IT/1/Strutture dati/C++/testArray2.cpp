/* 
file testArray2.cpp 
compilare con: g++ -std=c++11 testArray2.cpp
*/

#include <iostream>
#include <algorithm>
#include <array>

using std::cout;
using std::endl;
using std::array;
using std::copy;

int main() 
{
	/* crea un array di caratteri */

	array<char, 6> arr1 = {'C', 'i', 'a', 'o', ',', ' '};

	for (int i = 0; i < arr1.size(); i++) {
		cout << arr1.at(i);
	}

	cout << endl;

	char sect1[3];
	char sect2[3];
	char sect3[3];

	// copia i primi tre caratteri
	copy(arr1.begin(), arr1.begin()+3, sect1);

	// ...gli ultimi tre caratteri,
	copy(arr1.begin()+3, arr1.end(), sect2);

	// tre caratteri intermedi
	copy(arr1.begin()+1, arr1.begin()+4, sect3);

	for (char& c : sect1) {
		cout << c;
	}

	cout << endl;

	for (char& c : sect2) {
		cout << c;
	}

	cout << endl;

	for (char& c : sect3) {
		cout << c;
	}

	cout << endl;

	/* crea un secondo array */

	array<char, 6> arr2;

	arr2[0] = 'm';
	arr2[1] = 'o';
	arr2[2] = 'n';
	arr2[3] = 'd';
	arr2[4] = 'o';
	arr2[5] = '!';

	for (char& c : arr2) {
		cout << c;
	}

	cout << endl;

	/* concatena i due array */

	const int LEN = arr1.size() + arr2.size();
	array<char, LEN> arr3;

	copy(arr1.begin(), arr1.end(), arr3.begin());
	copy(arr2.begin(), arr2.end(), arr3.begin()+arr1.size());

	for (char& c : arr3) {
		cout << c;
	}

	cout << endl;
}

