/* file Esercizio30.java */

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

interface Shape {
	public abstract double volume();
	public abstract void draw();
}

class Cilinder implements Shape {
	private Circle base;
	private double h;

	public Cilinder(Circle base, double h) {
		this.base = base;
		this.h = h;
	}

	@Override
	public double volume() {
		return this.base.area() * this.h;
	}

	@Override
	public void draw() {
		System.out.println("Cilindro di raggio " + this.base.getR() + " centimetri e altezza " + this.h + " centimetri");
	}
}

class Cone implements Shape {
	private Circle base;
	private double h;

	public Cone(Circle base, double h) {
		this.base = base;
		this.h = h;
	}

	@Override
	public double volume() {
		return (this.base.area() * this.h) / 3;
	}

	@Override
	public void draw() {
		System.out.println("Cono di raggio " + this.base.getR() + " centimetri e altezza " + this.h + " centimetri");
	}
}

class Sphere implements Shape {
	private Circle circle;

	public Sphere(Circle circle) {
		this.circle = circle;
	}

	@Override
	public double volume() {
		return (4 * this.circle.area() * this.circle.getR()) / 3;
	}

	@Override
	public void draw() {
		System.out.println("Sfera di raggio " + this.circle.getR() + " centimetri");
	}
}

class Geometry {
	public Shape getSolid(String solid) {
		if (solid.equals("cilindro")) {
			return new Cilinder(new Circle(2.0), 3.0);
		}

		if (solid.equals("cono")) {
			return new Cone(new Circle(2.0), 3.0);
		}

		if (solid.equals("sfera")) {
			return new Sphere(new Circle(2.0));
		}

		return null;
	}
}

public class Esercizio30 {
	public static void main(String [] args) {
		Geometry geometry = new Geometry();

		Shape shape = null;

		shape = geometry.getSolid("cilindro");
		shape.draw();

		shape = geometry.getSolid("cono");
		shape.draw();

		shape = geometry.getSolid("sfera");
		shape.draw();
	}
}

