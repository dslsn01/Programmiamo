/* file esercizio16.cpp */

#include <iostream>

using std::cout;
using std::endl;

int rect(int b, int h) {
	return b * h;
}

int main() 
{
	int b = 1;
	int h = 1;

	while (h <= 10) {
		cout << "Area del rettangolo di base " << b << " e altezza " << h << " = " << rect(b, h) << " cm quadrati." << endl;
		h++;
		b += 2;
	}
}

