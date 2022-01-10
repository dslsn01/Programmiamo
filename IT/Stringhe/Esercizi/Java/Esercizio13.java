/* file Esercizio13.java */

public class Esercizio13 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una frase e leggi le singole parole: ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		String [] parts = s.split(" ");

		for (String w : parts) {
			System.out.println(w);
		}
	}
}

