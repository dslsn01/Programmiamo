/* file Esercizio23.java */

import java.util.SortedSet;
import java.util.TreeSet;

public class Esercizio23 {
	public static void main(String [] args) {
		SortedSet<Integer> a = new TreeSet<Integer>();

		a.add(0);
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);

		SortedSet<Integer> b = new TreeSet<Integer>();

		b.add(1);
		b.add(2);
		b.add(3);

		System.out.println("A = " + a);
		System.out.println("B = " + b);

		/* se tutti gli elementi di B sono anche elementi di A, allora B è un sottoinsieme di A */

		if (a.containsAll(b)) {
			System.out.println("L'insieme B è un sottoinsieme di A!");
		}
	}
}

