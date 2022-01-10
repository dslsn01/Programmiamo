/* file Esercizio29.java */

/* la classe Circle rappresenta una circonferenza */

class Circle {
	/* ogni circonferenza viene definita dal suo raggio */
	private double r;

	public Circle(double r) {
		setR(r);
	}

	/* area del cerchio = Pi greco * raggio al quadrato */
	public double area() {
		return Math.PI * this.r * this.r;
	}

	public double getR() {
		return this.r;
	}

	public void setR(double r) {
		this.r = r;
	}
}

/* la classe Sphere rappresenta una sfera */

class Sphere {
	private Circle circle;

	/* la sfera viene definita dal suo cerchio massimo */
	public Sphere(Circle circle) {
		this.circle = circle;
	}

	/* volume della sfera: (4 * 3.14 * r^3) / 3 */
	public double volume() {
		return (4 * this.circle.area() * this.circle.getR()) / 3;
	}
}

public class Esercizio29 {
	public static void main(String [] args) {
		Circle circle = new Circle(2.0);
		Sphere solid = new Sphere(circle);

		System.out.println("Area circonferenza alla base: " + String.format("%.2f", circle.area()) + " centimetri quadrati.");
		System.out.println("Volume sfera: " + String.format("%.2f", solid.volume()) + " centimetri cubi.");
	}
}

