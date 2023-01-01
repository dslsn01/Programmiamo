/* file Esercizio3.java */

public class Esercizio3 {
	static int s(int n) {
		return n + 1;
	}

	public static void main(String [] args) {
		for (int i = 0; i < 10; i++) {
			System.out.print(s(s(i)) + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

