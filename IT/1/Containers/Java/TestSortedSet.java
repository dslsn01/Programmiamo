/* file TestSortedSet.java */

import java.util.SortedSet;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.Iterator;

public class TestSortedSet {
	public static void main(String [] args) {
		/* dichiara un Set di numeri interi */

		SortedSet<Integer> n = new TreeSet<Integer>();

		/* i numeri sono aggiunti in ordine casuale, ma il TreeSet li riordina automaticamente secondo l'ordinamento naturale */

		n.add(2);
		n.add(0);
		n.add(1);

		System.out.println("N = " + n);

		/* verifica la presenza dello zero nel Set */

		if (n.contains(0)) {
			System.out.println("L'insieme N include lo zero.");
		}

		/* aggiunge il numero 3 al Set */

		n.add(3);

		/* scorre tutti gli elementi dell'insieme con un iteratore */

		Iterator<Integer> it = n.iterator();

		int i = 0;
		System.out.print("N = [");

		while (it.hasNext()) {
			Integer current = it.next();
			System.out.print(current);
			if (i < n.size() - 1) System.out.print(", ");
			i++;
		}

		System.out.println("]");

		/* aggiunge i numeri 4, 5, 6, 7 al Set */

		ArrayList<Integer> updates = new ArrayList<Integer>();
		updates.add(5);
		updates.add(4);
		updates.add(7);
		updates.add(6);

		n.addAll(updates);
		System.out.println("N = " + n);

		/* recupera il primo elemento (lo zero) dal Set, usando un iteratore */

		System.out.println("Primo elemento di N: " + n.first());

		/* cancella il numero 7 dal Set */

		n.remove(7);
		System.out.println("N = " + n);

		/* cancella tutti gli elementi del Set */

		n.clear();
		System.out.println("Cardinalità dell'insieme vuoto: " + n.size());
		System.out.println("N = " + n);
	}
}

