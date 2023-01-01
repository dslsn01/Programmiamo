/* file esercizio25.cpp */

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
		double getX() const;
		void setX(double);
		double getY() const;
		void setY(double);

	friend ostream& operator<<(ostream& os, const Point2d&);
};

Point2d::Point2d(double x, double y) {
	this->setX(x);
	this->setY(y);
}

double Point2d::getX() const {
	return this->x;
}

void Point2d::setX(double x) {
	this->x = x;
}

double Point2d::getY() const {
	return this->y;
}

void Point2d::setY(double y) {
	this->y = y;
}

ostream& operator<<(ostream& os, const Point2d& p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

class Point3d : public Point2d {
	private:
		double z;

	public:
		Point3d(double, double, double);
		double getZ();
		void setZ(double);

	friend ostream& operator<<(ostream& os, const Point3d&);
};

Point3d::Point3d(double x, double y, double z) : Point2d(x, y) {
	this->setZ(z);
}

double Point3d::getZ() {
	return this->z;
}

void Point3d::setZ(double z) {
	this->z = z;
}

ostream& operator<<(ostream& os, const Point3d& p) {
	return os << "(" << p.getX() << ", " << p.getY() << ", " << p.z << ")";
}

class Segment {
	private:
		Point3d* a;
		Point3d* b;

	public:
		Segment(Point3d*, Point3d*);
		Point3d* getA();
		void setA(Point3d*);
		Point3d* getB();
		void setB(Point3d*);
		double length();
};

Segment::Segment(Point3d* a, Point3d* b) {
	this->setA(a);
	this->setB(b);
}

Point3d* Segment::getA() {
	return this->a;
}

void Segment::setA(Point3d* a) {
	this->a = a;
}

Point3d* Segment::getB() {
	return this->b;
}

void Segment::setB(Point3d* b) {
	this->b = b;
}

double Segment::length() {
	return sqrt(pow((this->a->getX() - this->b->getX()), 2.0) + pow((this->a->getY() - this->b->getY()), 2.0) + pow((this->a->getZ() - this->b->getZ()), 2.0));
}

int main() {
	Point3d o(0.0, 0.0, 0.0);
	Point3d p(1.0, 2.0, 3.0);
	Segment s(&o, &p);

	cout << "O = " << o << " P = " << p << endl;
	cout << "Distanza tra i due punti: " << setprecision(3) << s.length() << " centimetri." << endl;
}

