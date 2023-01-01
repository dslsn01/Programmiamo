/* file Esercizio1.java */

import java.util.Random;

public class Esercizio1 {
	private static int f(int a, int b, int c) {
		if (a > b) {
			return a > c ? a : c;
		}
		else {
			return b > c ? b : c;
		}
	}

	public static void main(String [] args) {
		Random rand = new Random();
		int a = rand.nextInt(10)+1;
		int b = rand.nextInt(10)+1;
		int c = rand.nextInt(10)+1;

		System.out.println("a=" + a + ", b=" + b + ", c=" + c);
		System.out.println("Numero maggiore: " + f(a, b, c));
	}
}

