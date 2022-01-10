/* file HelloString.java */

public class HelloString {
	public static void main(String [] args) {
		/* dichiara una stringa di caratteri */

		String s = "Ciao, mondo!";

		/* stampa la stringa sulla console, carattere per carattere */

		for (int i = 0; i < s.length(); i++) {	
			System.out.print(s.charAt(i));
		}

		/* aggiunge un'interruzione di riga */

		System.out.print(System.lineSeparator());
	}
}

