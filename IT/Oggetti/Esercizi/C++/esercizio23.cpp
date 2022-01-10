/* file esercizio23.cpp */

#include <iostream>

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

int main() {
	Point2d o(0.0, 0.0);
	Point2d p(1.0, 2.0);

	cout << "O = " << o << " P = " << p << endl;
}

