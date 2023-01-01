/* file Esercizio4.java */

public class Esercizio4 {
	static int abs(int n) {
		return n >= 0 ? n : -n;
	}

	public static void main(String [] args) {
		for (int i = -7; i <= 7; i++) {
			System.out.print(abs(i) + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

