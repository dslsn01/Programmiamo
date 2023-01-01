/* file TestVector2.java */

import java.util.List;
import java.util.Vector;

public class TestVector2 {
	public static void main(String [] args) {
		/* crea un vettore di stringhe */

		Vector<String> vect1 = new Vector<String>();

		vect1.add("tigre");
		vect1.add("giraffa");
		vect1.add("elefante");
		vect1.add("zebra");
		vect1.add("coccodrillo");

		System.out.println(vect1);

		/* sezione di vettori */

		/* seleziona i primi tre elementi... */

		List sect1 = vect1.subList(0, 3);
		System.out.println(sect1);

		/* ...gli ultimi due elementi, */

		List sect2 = vect1.subList(3, vect1.size());
		System.out.println(sect2);

		/* ...e gli elementi con indice da 1 a 3 */

		List sect3 = vect1.subList(1, 4);
		System.out.println(sect3);

		/* crea un altro vettore di stringhe */

		Vector<String> vect2 = new Vector<String>();

		vect2.add("gnu");
		vect2.add("cane");
		vect2.add("lama");
		vect2.add("lupo");
		vect2.add("orso");
		vect2.add("cavallo");

		System.out.println(vect2);

		/* concatena i due vettori */

		vect1.addAll(vect2);
		System.out.println(vect1);
	}
}

