/* file TestArrayList2.java */

import java.util.List;
import java.util.ArrayList;

public class TestArrayList2 {
	public static void main(String [] args) {
		/* crea una lista di stringhe */

		ArrayList<String> arr1 = new ArrayList<String>();

		arr1.add("tigre");
		arr1.add("giraffa");
		arr1.add("elefante");
		arr1.add("zebra");
		arr1.add("coccodrillo");

		System.out.println(arr1);

		/* sezione di liste */

		/* seleziona i primi tre elementi... */

		List sect1 = arr1.subList(0, 3);
		System.out.println(sect1);

		/* ...gli ultimi due elementi, */

		List sect2 = arr1.subList(3, arr1.size());
		System.out.println(sect2);

		/* ...e gli elementi con indice da 1 a 3 */

		List sect3 = arr1.subList(1, 4);
		System.out.println(sect3);

		/* crea un'altra lista di stringhe */

		ArrayList<String> arr2 = new ArrayList<String>();

		arr2.add("gnu");
		arr2.add("cane");
		arr2.add("lama");
		arr2.add("lupo");
		arr2.add("orso");
		arr2.add("cavallo");

		System.out.println(arr2);

		/* concatena le due liste */

		arr1.addAll(arr2);
		System.out.println(arr1);
	}
}

