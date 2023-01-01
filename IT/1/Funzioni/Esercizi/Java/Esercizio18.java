/* file Esercizio18.java */

import java.util.Random;

public class Esercizio18 {
	static double recp(int n) {
		if (n == 0) return Double.NaN;
		return (double) 1/n;
	}

	public static void main(String [] args) {
		Random randomizer = new Random(System.currentTimeMillis());
		randomizer.nextInt();

		for (int i = 0; i < 5; i++) {
			int r = randomizer.nextInt(15) + 2;
			double rp = recp(r);
			System.out.println("Il reciproco di " + r + " è " + String.format("%.2f", rp) + ".");
		}
	}
}

