/* file opOverloading.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Vector3D
{
	private:
		double x;
		double y;
		double z;

	public:
		Vector3D(double x, double y, double z);

	/* il nuovo operatore "*" (prodotto scalare) è definito come membro friend' per accedere alle variabili private */

	friend Vector3D operator*(const Vector3D &vector, const double& scalar);
	friend std::ostream& operator<<(std::ostream&, const Vector3D&);
};

/* il costruttore della classe Vector3D riceve come parametri le coordinate x, y, z */

Vector3D::Vector3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

/* ridefiniamo l'operatore "*". Il "nuovo" operatore "prodotto scalare per vettore" riceve un parametro scalare e lo moltiplica per le coordinate x, y, z del vettore originale */

Vector3D operator*(const Vector3D &vector, const double& scalar) 
{
	Vector3D result(0, 0, 0);

	result.x = vector.x * scalar;
	result.y = vector.y * scalar;
	result.z = vector.z * scalar;

	return result;
}

/* ridefiniamo anche l'operatore "<<" per stampare un vettore sulla console */

ostream& operator<<(ostream &os, const Vector3D& v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

int main()
{
	Vector3D v(1.0, 2.0, 3.0);

	cout << "Vettore v = " << v << endl;

	double scalar = 2.0;

	/* utilizza l'operatore "*" appena ridefinito per eseguire il prodotto di uno scalare per un vettore */

	Vector3D v2 = v * scalar;

	cout << "Vettore v2 = " << v2 << endl;
}

