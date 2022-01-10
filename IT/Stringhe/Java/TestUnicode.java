/* file TestUnicode.java */

public class TestUnicode {
	public static void main(String [] args) {
		System.out.println("\tCaratteri ASCII stampabili (32-127): ");

		int i = 0;
		for (i = 32; i <= 127; i++) {
			// salta il carattere di delete
			if (i == 127) continue;
			char c = (char) i;
			System.out.print(c + " ");
		}

		System.out.print(System.lineSeparator());
		System.out.println("\tCaratteri Unicode stampabili (160-255): ");

		for (i += 32; i <= 255; i++) {
			char c = (char) i;
			System.out.print(c + " ");
		}

		System.out.print(System.lineSeparator());

		String s = System.console().readLine("Scrivi _una sola parola_ (no numeri, spazi o punteggiatura: ammessi caratteri accentati): ");

		int l = s.length();
		int k = 0;

		for (char c : s.toCharArray()) {
			if (!Character.isLetter(c)) break;
			k++;
		}

		// converte la String in un array di bytes
		byte [] b = s.getBytes();

		if (k == l) {
			System.out.println("La stringa \"" + s + "\" contiene " + l + " caratteri, per un totale di " + b.length + " byte.");
		}
		else System.out.println("Parola non valida!");

		String s2 = new String(b);

		System.out.println("La stringa convertita da byte[] a String (\"" + s2 + "\"), contiene " + s.length() + " caratteri.");
	}
}

