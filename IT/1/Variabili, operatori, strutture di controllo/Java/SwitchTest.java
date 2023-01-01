/* file SwitchTest.java */

public class SwitchTest {
	public static void main(String[] args) {
		String s = System.console().readLine("Inserisci un intero compreso tra 1 e 3: ");

		if (!s.matches("[\\d]+")) {
			System.out.println("Numero non valido!");
			return;
		}

		int n = Integer.parseInt(s);

		switch (n) {
			case 1: 
				System.out.println("Hai digitato il numero 1.");
				break;

			case 2: 
				System.out.println("Hai digitato il numero 2.");
				break;

			case 3: 
				System.out.println("Hai digitato il numero 3.");
				break;

			default: 
				System.out.println("Numero fuori dell'intervallo!");
				break;
		}
	}
}

