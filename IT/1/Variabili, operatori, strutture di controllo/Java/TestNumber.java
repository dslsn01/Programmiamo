/* file TestNumber.java */

public class TestNumber {
	public static void main(String [] args) {
		/* legge un numero da tastiera */

		String s = System.console().readLine("Inserisci un intero positivo compreso tra 2 e 10: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		/* converte la stringa in un numero intero */

		int n = Integer.parseInt(s);

		/* controlla che il valore inserito non sia negativo o nullo */

		if (!(n > 0) || n == 0) {
			System.out.println("Il numero inserito dev'essere maggiore di zero!");
		}
		else
		{
			/* controlla che il valore inserito non sia minore di 2 o maggiore di 10 */

			if (n >= 2 && n <= 10) {
				System.out.println("Hai digitato " + n + ".");
			}
			else
			{
				System.out.println("Valore fuori dall'intervallo!");
			}
		}
	}
}

