/* file Esercizio28.java */

public class Esercizio28 {
	static int fibonacci(int n) {
		int a = 0;
		int b = 1;

		for (int i = 0; i < n; i++) {
			int prev = a;
			a = b;
			b = prev + b;
		}

		return a;
	}

	public static void main(String [] args) {
		for (int i = 1; i <= 20; i++) {
			System.out.print(fibonacci(i) + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

