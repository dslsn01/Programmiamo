/* file Esercizio27.java */

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

/* la classe Cilinder rappresenta un cilindro tridimensionale */

class Cilinder {
	private Circle base;
	private double h;

	/* ogni cilindro viene definito da altezza e circonferenza alla base */
	public Cilinder(Circle base, double h) {
		this.base = base;
		this.h = h;
	}

	/* volume del cilindro: 3.14 * r^2 * h */
	public double volume() {
		return this.base.area() * this.h;
	}
}

public class Esercizio27 {
	public static void main(String [] args) {
		Circle base = new Circle(2.0);
		Cilinder solid = new Cilinder(base, 3.0);

		System.out.println("Area circonferenza alla base: " + String.format("%.2f", base.area()) + " centimetri quadrati.");
		System.out.println("Volume cilindro: " + String.format("%.2f", solid.volume()) + " centimetri cubi.");
	}
}

