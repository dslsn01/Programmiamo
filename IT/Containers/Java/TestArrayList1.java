/* file TestArrayList1.java */

import java.util.ArrayList;

public class TestArrayList1 {
	public static void main(String [] args) {
		/* dichiara una lista di stringhe */

		ArrayList<String> arr = new ArrayList<String>();

		arr.add("tigre");
		arr.add("giraffa");
		arr.add("elefante");

		/* stampa il contenuto della lista */

		System.out.println(arr);

		/* verifica la presenza dell'"elefante" nella lista, se presente stampa la sua posizione */

		if (arr.contains("elefante")) {
			int index = arr.indexOf("elefante");
			System.out.println("Nella lista c'è un elefante alla posizione " + index);
		}

		/* modifica il secondo elemento in lista da "giraffa" a "cane" */

		System.out.println("Sostituisco la giraffa con un cane.");
		arr.set(1, "cane");
		System.out.println(arr);

		/* possiamo aggiungere e togliere elementi da una lista in qualsiasi momento */

		System.out.println("Aggiungo una balenottera azzurra.");
		arr.add(3, "balenottera");
		System.out.println(arr);
		System.out.println("La lista contiene " + arr.size() + " elementi.");

		/* rimuove un elemento dalla lista */

		System.out.println("Rimuovo il cane.");
		arr.remove("cane");
		System.out.println(arr);
		System.out.println("La lista contiene " + arr.size() + " elementi.");
	}
}

