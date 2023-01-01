/* file Esercizio.java */

import java.util.Locale;

public class Esercizio29 {
	private static double fsqr(double n, double g) {
		if (Math.abs(g*g - n) <= 0.0001) return g;
		double mid = (g + n/g)/2;
		return fsqr(n, mid);
	}

	public static void main(String [] args) {
		int nums[] = {2, 5, 7, 9, 16, 32, 64, 81};
		for (int i = 0; i < 8; i++) {
			int n = nums[i];
			double s = fsqr(n, n/2);
			System.out.println("sqrt(" + n + ") = " + String.format(Locale.ROOT, "%.5f", s));
		}
	}
}

