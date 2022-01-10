/* file esercizio27.cpp */

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::ostream;

/* la classe Circle rappresenta una circonferenza */

class Circle {
	/* ogni circonferenza viene definita dal suo raggio */
	private:
		double r;

	public:
		Circle(double);
		double area();
};

Circle::Circle(double r) {
	this->r = r;
}

/* area del cerchio = Pi greco * raggio al quadrato */
double Circle::area() {
	return M_PI * this->r * this->r;
}

/* la classe Cilinder rappresenta un cilindro tridimensionale */

class Cilinder {
	/* ogni cilindro viene definito da altezza e circonferenza alla base */
	private:
		Circle base;
		double h;

	public:
		Cilinder(Circle&, double);
		double volume();
};

Cilinder::Cilinder(Circle& base, double h) : base(base) {
	this->h = h;
}

/* volume del cilindro: 3.14 * r^2 * h */
double Cilinder::volume() {
	return this->base.area() * this->h;
}

int main()
{
	Circle circle(2.0);

	cout << "Area circonferenza alla base: " << setprecision(4) << circle.area() << " centimetri quadrati." << endl;

	Cilinder solid(circle, 3.0);

	cout << "Volume cilindro: " << setprecision(4) << solid.volume() << " centimetri cubi." << endl;
}

