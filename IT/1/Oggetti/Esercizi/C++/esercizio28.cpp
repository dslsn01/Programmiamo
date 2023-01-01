/* file esercizio28.cpp */

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

/* la classe Cone rappresenta un cono tridimensionale */

class Cone {
	/* ogni cono viene definito da altezza e circonferenza alla base */
	private:
		Circle *base;
		double h;

	public:
		Cone(Circle *base, double h);
		double volume();
};

Cone::Cone(Circle *base, double h) {
	this->base = base;
	this->h = h;
}

/* volume del cono: (3.14 * r^2 * h) / 3 */
double Cone::volume() {
	return (this->base->area() * this->h) / 3;
}

int main()
{
	Circle *circle = new Circle(2.0);

	cout << "Area circonferenza alla base: " << setprecision(4) << circle->area() << " centimetri quadrati." << endl;

	Cone *solid = new Cone(circle, 3.0);

	cout << "Volume cono: " << setprecision(4) << solid->volume() << " centimetri cubi." << endl;

	delete circle;
	delete solid;
}

