/* file Esercizio23.java */

public class Esercizio23 {
	public static void main(String [] args) {
		String user = "";

		while (user.isEmpty()) {
			try {
				user = System.console().readLine("Scrivi il tuo nome: ");

				if (user.isEmpty()) {
					throw new IllegalArgumentException("Nome non valido!");
				}

				System.out.println("Ciao, " + user + "!");
			}
			catch (IllegalArgumentException e) {
				System.out.println(e.getMessage());
			}
		}

		System.out.println("Fine del programma.");
	}
}

