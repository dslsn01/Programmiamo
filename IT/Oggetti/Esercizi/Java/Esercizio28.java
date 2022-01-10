/* file Esercizio28.java */

/* la classe Circle rappresenta una circonferenza */

class Circle {
	/* ogni circonferenza viene definita dal suo raggio */
	private double r;

	public Circle(double r) {
		this.r = r;
	}

	/* area del cerchio = Pi greco * raggio al quadrato */
	public double area() {
		return Math.PI * this.r * this.r;
	}
}

/* la classe Cone rappresenta un cono tridimensionale */

class Cone {
	private Circle base;
	private double h;

	/* ogni cono viene definito da altezza e circonferenza alla base */
	public Cone(Circle base, double h) {
		this.base = base;
		this.h = h;
	}

	/* volume del cono: (3.14 * r^2 * h) / 3 */
	public double volume() {
		return (this.base.area() * this.h) / 3;
	}
}

public class Esercizio28 {
	public static void main(String [] args) {
		Circle base = new Circle(2.0);
		Cone solid = new Cone(base, 3.0);

		System.out.println("Area circonferenza alla base: " + String.format("%.2f", base.area()) + " centimetri quadrati.");
		System.out.println("Volume cono: " + String.format("%.2f", solid.volume()) + " centimetri cubi.");
	}
}

