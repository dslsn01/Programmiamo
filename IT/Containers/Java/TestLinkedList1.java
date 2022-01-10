/* file TestLinkedList1.java */

import java.util.LinkedList;

public class TestLinkedList1 {
	public static void main(String [] args) {
		/* dichiara una lista linkata di stringhe */

		LinkedList<String> li = new LinkedList<String>();

		li.add("tigre");
		li.add("giraffa");
		li.add("elefante");

		/* stampa il contenuto della lista */
	
		System.out.println(li);

		/* verifica la presenza dell'"elefante" nella lista linkata, se presente stampa la sua posizione */

		if (li.contains("elefante")) {
			int index = li.indexOf("elefante");
			System.out.println("Nella lista c'è un elefante alla posizione " + index);
		}

		/* modifica il secondo elemento in lista da "giraffa" a "cane" */

		System.out.println("Sostituisco la giraffa con un cane.");
		li.set(1, "cane");
		System.out.println(li);

		/* possiamo aggiungere e togliere elementi da una lista linkata in qualsiasi momento */

		System.out.println("Aggiungo una balenottera azzurra.");
		li.add(3, "balenottera");
		System.out.println(li);
		System.out.println("La lista degli animali contiene " + li.size() + " elementi.");

		/* rimuove un elemento dalla lista linkata */

		System.out.println("Rimuovo il cane.");
		li.remove("cane");
		System.out.println(li);
		System.out.println("La lista degli animali contiene " + li.size() + " elementi.");	
	}
}

