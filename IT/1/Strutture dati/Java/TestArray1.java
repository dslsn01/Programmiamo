/* file TestArray1.java */

public class TestArray1 {
	public static void main(String [] args) {
		/* dichiara un array di stringhe */

		String arr[] = {"tigre", "giraffa", "elefante"};

		/* stampa il contenuto dell'array con un ciclo for */

		for (int i = 0; i < arr.length; i++) {
			System.out.println(i + ") " + arr[i]);
		}

		/* verifica la presenza dell'"elefante" nella lista, se presente stampa la sua posizione */

		for (int i = 0; i < arr.length; i++) {
			String e = arr[i];
			if ("elefante".equals(e)) {
				System.out.println("Nella lista c'è un elefante alla posizione " + i + ".");
			}
		}

		/* modifica il secondo elemento in lista da "giraffa" a "cane" */

		System.out.println("Sostituisco la giraffa con un cane.");
		arr[1] = "cane";

		for (String e : arr) {
			System.out.println(e);
		}
	}
}

