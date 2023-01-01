/* file Esercizio19.java */

import java.util.Locale;

public class Esercizio19 {
	public static void main(String [] args) {
		// stampa il risultato dell'operazione 1+3.14 tra un numero intero e un decimale
		System.out.println("1 + 3.14 = " + String.format(Locale.ROOT, "%.2f", 1 + 3.14));
	}
}

