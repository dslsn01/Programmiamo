/* file Esercizio26.java */

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

class Point3d extends Point2d {
	private double z;

	public Point3d(double x, double y, double z) {
		super(x, y);
		this.setZ(z);
	}

	public double getZ() {
		return this.z;
	}

	public void setZ(double z) {
		this.z = z;
	}

	@Override
	public String toString() {
		return "(" + this.getX() + ", " + this.getY() + ", " + this.z + ")";
	}
}

class Segment {
	private Point3d a;
	private Point3d b;

	public Segment(Point3d a, Point3d b) {
		this.setA(a);
		this.setB(b);
	}

	public Point3d getA() {
		return this.a;
	}

	public void setA(Point3d a) {
		this.a = a;
	}

	public Point3d getB() {
		return this.b;
	}

	public void setB(Point3d b) {
		this.b = b;
	}

	public double length() {
		return Math.sqrt(Math.pow((this.a.getX() - this.b.getX()), 2.0) + Math.pow((this.a.getY() - this.b.getY()), 2.0) + Math.pow((this.a.getZ() - this.b.getZ()), 2.0));
	}
}

public class Esercizio25 {
	public static void main(String [] args) {
		Point3d o = new Point3d(0, 0, 0);
		Point3d p = new Point3d(1, 2, 3);
		Segment s = new Segment(o, p);

		System.out.println(o + " " + p);
		System.out.println("Distanza tra i due punti: " + String.format("%.2f", s.length()) + " centimetri.");
	}
}

