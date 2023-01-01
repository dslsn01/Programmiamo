/* file Esercizio17.java */

public class Esercizio17 {
	static int rect(int b, int h) {
		return b * h;
	}

	static double triangle(int b, int h) {
		return (double) rect(b, h) / 2;
	}

	public static void main(String [] args) {
		int b = 1;
		int h = 1;

		while (h <= 10) {
			System.out.println("Area del triangolo di base " + b + " e altezza " + h + " = " + triangle(b, h) + " cm quadrati.");
			h++;
			b += 2;
		}
	}
}

