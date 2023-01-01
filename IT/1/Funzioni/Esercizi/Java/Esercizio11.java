/* file Esercizio11.java */

public class Esercizio11 {
	static boolean multiple(int a, int b) {
		if (a == 0 || b == 0) return false;
		return a <= b ? b % a == 0 : a % b == 0;
	}

	public static void main(String [] args) {
		int a = 5;
		int b = 10;
		int c = 11;

		System.out.println(b + " è multiplo di " + a + "? " + multiple(a, b));
		System.out.println(c + " è multiplo di " + a + "? " + multiple(c, a));
	}
}

