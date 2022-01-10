/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::ostream;

class Circle {
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

double Circle::area() {
	return M_PI * this->r * this->r;
}

double Circle::getR() {
	return this->r;
}

void Circle::setR(double r) {
	this->r = r;
}

class Shape {
	public:
		virtual ~Shape();
		virtual double volume() = 0;
		virtual void draw() = 0;
};

// le classi polimorfe devono avere un distruttore virtuale!
Shape::~Shape() {}

class Cilinder : public Shape {
	private:
		Circle *base;
		double h;

	public:
		Cilinder(Circle *base, double h);
		double volume() override;
		void draw() override;
};

Cilinder::Cilinder(Circle *base, double h) {
	this->base = base;
	this->h = h;
}

double Cilinder::volume() {
	return this->base->area() * this->h;
}

void Cilinder::draw() {
	cout << "Cilindro di raggio " << this->base->getR() << " centimetri e altezza " << this->h << " centimetri" << "." << endl;
}

class Cone : public Shape {
	private:
		Circle *base;
		double h;

	public:
		Cone(Circle *base, double h);
		double volume() override;
		void draw() override;
};

Cone::Cone(Circle *base, double h) {
	this->base = base;
	this->h = h;
}

double Cone::volume() {
	return (this->base->area() * this->h) / 3;
}

void Cone::draw() {
	cout << "Cono di raggio " << this->base->getR() << " centimetri e altezza " << this->h << " centimetri" << "." << endl;
}

class Sphere : public Shape {
	private:
		Circle *circle;

	public:
		Sphere(Circle*);
		double volume() override;
		void draw() override;
};

Sphere::Sphere(Circle *circle) {
	this->circle = circle;
}

double Sphere::volume() {
	return (4 * this->circle->area() * this->circle->getR()) / 3;
}

void Sphere::draw() {
	cout << "Sfera di raggio " << this->circle->getR() << " centimetri." << endl;
}

class Geometry {
	public:
		Shape* getSolid(string);
};

Shape* Geometry::getSolid(string solid) {
	if (solid == "cilindro") {
		return new Cilinder(new Circle(2.0), 3.0);
	}

	if (solid == "cono") {
		return new Cone(new Circle(2.0), 3.0);
	}

	if (solid == "sfera") {
		return new Sphere(new Circle(2.0));
	}

	return nullptr;
}

int main()
{
	Geometry *geometry = new Geometry();

	Shape* shape = nullptr;

	shape = geometry->getSolid("cilindro");
	shape->draw();
	delete shape;

	shape = geometry->getSolid("cono");
	shape->draw();
	delete shape;

	shape = geometry->getSolid("sfera");
	shape->draw();
	
	delete shape;
	delete geometry;
}

