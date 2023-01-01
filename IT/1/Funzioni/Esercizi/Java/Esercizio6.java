/* file Esercizio6.java */

public class Esercizio6 {
	static boolean even(int n) {
		return n % 2 == 0 ? true : false;
	}

	public static void main(String [] args) {
		int a = 2;
		int b = 3;

		System.out.println(a + " è pari? " + even(a));
		System.out.println(b + " è pari? " + even(b));
	}
}

