/* file Esercizio20.java */

public class Esercizio20 {
	public static void main(String [] args) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				if (j > i) {
					System.out.print("0" + " ");
				}
				else {
					System.out.print("1" + " ");
				}
			}

			System.out.print(System.lineSeparator());
		}
	}
}

