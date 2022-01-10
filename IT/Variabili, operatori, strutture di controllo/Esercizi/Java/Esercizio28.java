/* file Esercizio28.java */

public class Esercizio28 {
	public static void main(String [] args) {
		int i = 0;
		int x = 0;

		while (i < 10) {
			String s = System.console().readLine("Numero corrente: ");

			if (!s.matches("[\\d]+")) {
				System.out.println("Numero non valido!");
				continue;
			}

			int n = Integer.parseInt(s);

			if (n > x) {
				x = n;
			}
			i++;
		}

		System.out.println("Il numero più grande è " + x + ".");
	}
}

