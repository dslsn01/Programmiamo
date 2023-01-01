/* file esercizio24.cpp */

#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::ostream;

class Point2d {
	private:
		double x;
		double y;

	public:
		Point2d(double, double);
		double getX();
		void setX(double);
		double getY();
		void setY(double);

	friend ostream& operator<<(ostream& os, const Point2d&);
};

Point2d::Point2d(double x, double y) {
	this->setX(x);
	this->setY(y);
}

double Point2d::getX() {
	return this->x;
}

void Point2d::setX(double x) {
	this->x = x;
}

double Point2d::getY() {
	return this->y;
}

void Point2d::setY(double y) {
	this->y = y;
}

ostream& operator<<(ostream& os, const Point2d& p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

class Segment {
	private:
		Point2d* a;
		Point2d* b;

	public:
		Segment(Point2d*, Point2d*);
		Point2d* getA();
		void setA(Point2d*);
		Point2d* getB();
		void setB(Point2d*);
		double length();
};

Segment::Segment(Point2d* a, Point2d* b) {
	this->setA(a);
	this->setB(b);
}

Point2d* Segment::getA() {
	return this->a;
}

void Segment::setA(Point2d* a) {
	this->a = a;
}

Point2d* Segment::getB() {
	return this->b;
}

void Segment::setB(Point2d* b) {
	this->b = b;
}

double Segment::length() {
	return sqrt(pow((this->a->getX() - this->b->getX()), 2.0) + pow((this->a->getY() - this->b->getY()), 2.0));
}

int main() {
	Point2d o(0.0, 0.0);
	Point2d p(1.0, 2.0);
	Segment s(&o, &p);

	cout << "O = " << o << " P = " << p << endl;
	cout << "Distanza tra i due punti: " << setprecision(3) << s.length() << " centimetri." << endl;
}

