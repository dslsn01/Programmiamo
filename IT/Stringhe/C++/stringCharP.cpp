/* file stringsCharP.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	/* stringa "standard" */

	string s1 = "foo";

	/* stringa in "stile C", in formato const char* */
	
	const char *s2 = "bar";

	cout << s1 << endl;
	cout << s2 << endl;

	/* converte la stringa da const char* a stringa standard */

	string s3 = s2;

	cout << s3 << endl;

	/* converte la std::string in puntatore const char* */

	const char *s4 = s1.c_str();

	cout << s4 << endl;
}

