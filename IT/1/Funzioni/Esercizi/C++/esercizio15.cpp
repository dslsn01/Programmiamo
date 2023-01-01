/* file esercizio15.cpp */

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double exp(double b, double ex) {
	return pow(b, ex);
}

int main() 
{
	cout << "Calcolo delle potenze." << endl;

	double b = 1;
	double ex = 2;

	while (ex <= 10) {
		double p = exp(b, ex);
		cout << "Potenza di " << b << " elevato a " << ex << " = " << p << endl;
		b++;
		ex++;
	}
}

