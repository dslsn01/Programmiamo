/* file stringComparison.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str1 = "Ciao, mondo!";
	string str2 = "Ciao, mondo!";

	bool equals = (str1 == str2);
	
	if (equals == true)
	{
		cout << "Le stringhe \"" << str1 << "\" e \"" << str2 << "\" sono uguali." << endl;
	}
	else
	{
		cout << "Le stringhe \"" << str1 << "\" e \"" << str2 << "\" non sono uguali!" << endl;
	}
}

