/* file echo.cpp */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() 
{
	cout << "Scrivi qualcosa: ";
	string s;
	getline(cin, s);

	cout << s << endl;
}

