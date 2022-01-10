/* file Esercizio14.java */

public class Esercizio14 {
	public static void main(String [] args) {
		String s = System.console().readLine("Scrivi una frase e leggi le singole parole: ");

		if (s.isEmpty()) {
			System.out.println("Stringa vuota!");
			return;
		}

		String [] parts = s.split("[\\s\\.,?!]+");

		for (String w : parts) {
			System.out.println(w);
		}
	}
}

