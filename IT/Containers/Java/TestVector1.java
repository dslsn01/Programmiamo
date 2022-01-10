/* file TestVector1.java */

import java.util.Vector;

public class TestVector1 {
	public static void main(String [] args) {
		/* dichiara un vettore di stringhe */

		Vector<String> vect = new Vector<String>();

		vect.add("tigre");
		vect.add("giraffa");
		vect.add("elefante");

		/* stampa il contenuto del vettore */

		System.out.println(vect);

		/* verifica la presenza dell'"elefante" nel vettore, se presente stampa la sua posizione */

		if (vect.contains("elefante")) {
			int index = vect.indexOf("elefante");
			System.out.println("Nel vettore c'è un elefante alla posizione " + index);
		}

		/* modifica il secondo elemento del vettore: da "giraffa" a "cane" */

		System.out.println("Sostituisco la giraffa con un cane.");
		vect.set(1, "cane");
		System.out.println(vect);

		/* aggiunge una balenottera nella seconda posizione del vettore */

		System.out.println("Aggiungo una balenottera azzurra.");
		vect.add(3, "balenottera");
		System.out.println(vect);
		System.out.println("Il vettore degli animali contiene " + vect.size() + " elementi.");

		/* rimuove un elemento dal vettore */

		System.out.println("Rimuovo il cane.");
		vect.remove("cane");
		System.out.println(vect);
		System.out.println("Il vettore degli animali contiene " + vect.size() + " elementi.");
	}
}

