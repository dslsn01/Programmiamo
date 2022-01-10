/* file Esercizio16.java */

public class Esercizio16 {
	static int rect(int b, int h) {
		return b * h;
	}

	public static void main(String [] args) {
		int b = 1;
		int h = 1;

		while (h <= 10) {
			System.out.println("Area del rettangolo di base " + b + " e altezza " + h + " = " + rect(b, h) + " cm quadrati.");
			b += 2;
			h++;
		}
	}
}

