/* file Esercizio24.java */

class Point2d {
	private double x;
	private double y;

	public Point2d(double x, double y) {
		this.setX(x);
		this.setY(y);
	}

	public double getX() {
		return this.x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return this.y;
	}

	public void setY(double y) {
		this.y = y;
	}

	@Override
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}
}

class Segment {
	private Point2d a;
	private Point2d b;

	public Segment(Point2d a, Point2d b) {
		this.setA(a);
		this.setB(b);
	}

	public Point2d getA() {
		return this.a;
	}

	public void setA(Point2d a) {
		this.a = a;
	}

	public Point2d getB() {
		return this.b;
	}

	public void setB(Point2d b) {
		this.b = b;
	}

	public double length() {
		return Math.sqrt(Math.pow((this.a.getX() - this.b.getX()), 2.0) + Math.pow((this.a.getY() - this.b.getY()), 2.0));
	}
}

public class Esercizio24 {
	public static void main(String [] args) {
		Point2d o = new Point2d(0, 0);
		Point2d p = new Point2d(1, 2);
		Segment s = new Segment(o, p);

		System.out.println(o + " " + p);
		System.out.println("Distanza tra i due punti: " + String.format("%.2f", s.length()) + " centimetri.");
	}
}

