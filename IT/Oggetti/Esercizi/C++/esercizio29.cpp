/* file esercizio29.cpp */

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
		double getR();
		void setR(double);
};

Circle::Circle(double r) {
	this->setR(r);
}

/* area del cerchio = Pi greco * raggio al quadrato */
double Circle::area() {
	return M_PI * this->r * this->r;
}

double Circle::getR() {
	return this->r;
}

void Circle::setR(double r) {
	this->r = r;
}

/* la classe Sphere rappresenta una sfera */

class Sphere {
	/* la sfera viene definita dal suo cerchio massimo */
	private:
		Circle *circle;

	public:
		Sphere(Circle*);
		double volume();
};

Sphere::Sphere(Circle *circle) {
	this->circle = circle;
}

/* volume della sfera: (4 * 3.14 * r^3) / 3 */
double Sphere::volume() {
	return (4 * this->circle->area() * this->circle->getR()) / 3;
}

int main()
{
	Circle *circle = new Circle(2.0);

	cout << "Area circonferenza massima: " << setprecision(4) << circle->area() << " centimetri quadrati." << endl;

	Sphere *solid = new Sphere(circle);

	cout << "Volume sfera: " << setprecision(4) << solid->volume() << " centimetri cubi." << endl;

	delete circle;
	delete solid;
}

