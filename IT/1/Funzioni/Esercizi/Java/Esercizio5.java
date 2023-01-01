/* file Esercizio5.java */

public class Esercizio5 {
	static boolean comp(int a, int b) {
		return a > b;
	}

	public static void main(String [] args) {
		int a = 5;
		int b = 10;

		System.out.println(a + " > " + b + "? " + comp(a, b));
		System.out.println(b + " > " + a + "? " + comp(b, a));
	}
}

