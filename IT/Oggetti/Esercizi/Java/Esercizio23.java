/* file Esercizio23.java */

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

public class Esercizio23 {
	public static void main(String [] args) {
		Point2d o = new Point2d(0, 0);
		Point2d p = new Point2d(1, 2);

		System.out.println("O = " + o + " P = " + p);
	}
}

