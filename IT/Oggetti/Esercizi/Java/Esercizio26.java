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

class Plane {
	private Point3d p1;
	private Point3d p2;
	private Point3d p3;

	public Plane(Point3d p1, Point3d p2, Point3d p3) {
		this.p1 = p1;
		this.p2 = p2;
		this.p3 = p3;
	}

	@Override
	public String toString() {
		return "Piano definito dai punti P1=" + this.p1 + ", P2=" + this.p2 + ", P3=" + this.p3;
	}
}

public class Esercizio26 {
	public static void main(String [] args) {
		Point3d p1 = new Point3d(0, 0, 0);
		Point3d p2 = new Point3d(1, 2, 3);
		Point3d p3 = new Point3d(3, 4, 5);

		Plane pi = new Plane(p1, p2, p3);

		System.out.println(pi);
	}
}

