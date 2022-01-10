/* file esercizio26.cpp */

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
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

class Plane {
	private:
		Point3d *p1;
		Point3d *p2;
		Point3d *p3;

	public:
		Plane(Point3d*, Point3d*, Point3d*);

	friend ostream& operator<<(ostream& os, const Plane&);
};

Plane::Plane(Point3d* p1, Point3d* p2, Point3d* p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

ostream& operator<<(ostream& os, const Plane& pi) {
	return os << "Piano definito dai punti P1=" << *pi.p1 << ", P2=" << *pi.p2 << ", P3=" << *pi.p3;
}

int main() {
	Point3d p1(0.0, 0.0, 0.0);
	Point3d p2(1.0, 2.0, 3.0);
	Point3d p3(3.0, 2.0, 1.0);

	Plane pi(&p1, &p2, &p3);

	cout << pi << endl;
}

