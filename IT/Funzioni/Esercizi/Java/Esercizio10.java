/* file Esercizio10.java */

import java.util.Locale;

public class Esercizio10 {
	static float divide(int a, int b) {
		return b != 0 ? (float)a / b : Float.NaN;
	}

	public static void main(String [] args) {
		int a = 10;
		int b = 3;
		int c = 0;

		System.out.println(a + " / " + b + " = " + String.format(Locale.ROOT, "%.3f", divide(a, b)));
		System.out.println(a + " / " + c + " = " + divide(a, c));
	}
}

