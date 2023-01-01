/* file Esercizio15.java */

public class Esercizio15 {
	public static void main(String [] args) {
		final int M = 10;
		final int N = 10;

		int i = 1;

		while (i <= M) {
			int j = 1;
			while (j <= N) {
				System.out.print((i * j) + "\t");
				j++;
			}
			i++;
			System.out.print(System.lineSeparator());
		}
	}
}

