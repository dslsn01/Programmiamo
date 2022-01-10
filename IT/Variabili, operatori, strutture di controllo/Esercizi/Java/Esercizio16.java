/* file Esercizio16.java */

public class Esercizio16 {
	public static void main(String [] args) {
		final int M = 10;
		final int N = 10;

		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				System.out.print((i * j) + "\t");
			}

			System.out.print(System.lineSeparator());
		}
	}
}

