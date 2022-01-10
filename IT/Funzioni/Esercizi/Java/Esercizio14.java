/* file Esercizio14.java */

public class Esercizio14 {
	static int cube(int n) {
		return n * n * n;
	}

	public static void main(String [] args) {
		for (int n = 1; n <= 10; n++) {
			System.out.println(n + " al cubo = " + cube(n));
		}
	}
}

