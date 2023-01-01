/* file Esercizio32.java */

public class Esercizio32 {
	public static void main(String [] args) {
		for (int i = 1; i <= 30; i++) {
			if (i % 5 == 0 & i % 3 == 0) {
				System.out.print("fizzbuzz ");
			}
			else if (i % 3 == 0) {
				System.out.print("fizz ");
			}
			else if (i % 5 == 0) {
				System.out.print("buzz ");
			}
			else {
				System.out.print(i + " ");
			}
		}

		System.out.print(System.lineSeparator());
	}
}

