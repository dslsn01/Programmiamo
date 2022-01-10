/* file Esercizio2.java */

public class Esercizio2 {
	static int s(int n) {
		return n + 1;
	}

	public static void main(String [] args) {
		for (int i = 0; i < 10; i++) {
			System.out.print(s(i) + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

