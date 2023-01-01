/* file TestHashMap.java */

import java.util.HashMap;

public class TestHashMap {
	public static void main(String [] args) {
		/* crea una mappa con tre coppie chiave-valore */

		HashMap<String, String> dict = new HashMap<String, String>();

		dict.put("nome", "John");
		dict.put("cognome", "Doe");
		dict.put("anni", "30");

		System.out.println(dict);

		/* verifica la presenza della chiave "name" nella mappa, e ne stampa il valore corrente */

		if (dict.containsKey("nome")) {
			System.out.println("Valore della chiave \"nome\": " + dict.get("nome"));
		}

		/* modifica e stampa il valore associato alla chiave "name" della mappa */

		dict.put("nome", "Steve");
		System.out.println("Nuovo valore della chiave \"nome\": " + dict.get("nome"));

		/* aggiunge una nuova coppia chiave-valore alla mappa */

		dict.put("stato civile", "sposato");

		System.out.println("Aggiunto stato civile.");
		System.out.println("Stampo le coppie chiave-valore.");

		for (String key : dict.keySet()) {
			System.out.print(key + "=" + dict.get(key) + " ");
		}

		System.out.print(System.lineSeparator());

		/* rimuove una coppia chiave-valore dalla mappa */ 

		dict.remove("stato civile");
		System.out.println("Stato civile rimosso.");
		System.out.println(dict);
	}
}

