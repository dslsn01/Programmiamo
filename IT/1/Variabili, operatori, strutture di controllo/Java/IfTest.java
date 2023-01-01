/* file IfTest.java */

public class IfTest {
	public static void main(String[] args) {
		/* legge da tastiera il numero intero digitato dall'utente */

		String s = System.console().readLine("Inserisci un intero: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		/* converte la stringa in un numero intero */

		int n = Integer.parseInt(s);

		/* controlla se il numero digitato sia pari o dispari */

		if (n % 2 == 0) {
			System.out.println(n + " è pari!");
		}
		else {
			System.out.println(n + " è dispari!");
		}
	}
}

