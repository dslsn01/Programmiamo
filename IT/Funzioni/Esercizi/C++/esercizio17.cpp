/* file esercizio17.cpp */

#include <iostream>

using std::cout;
using std::endl;

int rect(int b, int h) {
	return b * h;
}

double triangle(int b, int h) {
	return (double)rect(b, h) / 2;
}

int main() 
{
	int b = 1;
	int h = 1;

	while (h <= 10) {
		cout << "Area del triangolo di base " << b << " e altezza " << h << " = " << triangle(b, h) << " cm quadrati." << endl;
		h++;
		b += 2;
	}
}

