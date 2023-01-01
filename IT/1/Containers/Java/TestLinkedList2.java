/* file TestLinkedList2.java */

import java.util.List;
import java.util.LinkedList;

public class TestLinkedList2 {
	public static void main(String [] args) {
		/* crea una lista linkata di stringhe */

		LinkedList<String> li1 = new LinkedList<String>();

		li1.add("tigre");
		li1.add("giraffa");
		li1.add("elefante");
		li1.add("zebra");
		li1.add("coccodrillo");

		System.out.println(li1);

		/* sezione di liste */

		/* seleziona i primi tre elementi... */

		List sect1 = li1.subList(0, 3);
		System.out.println(sect1);

		/* ...gli ultimi due elementi, */

		List sect2 = li1.subList(3, li1.size());
		System.out.println(sect2);

		/* ...e gli elementi con indice da 1 a 4 */

		List sect3 = li1.subList(1, 4);
		System.out.println(sect3);

		/* crea un'altra lista linkata di stringhe */

		LinkedList<String> li2 = new LinkedList<String>();

		li2.add("gnu");
		li2.add("cane");
		li2.add("lama");
		li2.add("lupo");
		li2.add("orso");
		li2.add("cavallo");

		System.out.println(li2);

		/* concatena le due liste */

		li1.addAll(li2);
		System.out.println(li1);
	}
}

