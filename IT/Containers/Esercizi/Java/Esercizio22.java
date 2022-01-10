/* file Esercizio22.java */

import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Collections;

public class Esercizio22 {
	public static void main(String [] args) {
		SortedSet<Integer> a = new TreeSet<Integer>();

		a.add(0);
		a.add(1);
		a.add(2);

		SortedSet<Integer> b = new TreeSet<Integer>();

		b.add(3);
		b.add(4);
		b.add(5);

		SortedSet<Integer> c = new TreeSet<Integer>();

		c.add(2);
		c.add(3);
		c.add(4);

		System.out.println("A = " + a);
		System.out.println("B = " + b);
		System.out.println("C = " + c);

		/* verifica se gli insiemi A e B sono disgiunti */

		if (Collections.disjoint(a, b)) {
			System.out.println("Gli insiemi A e B sono disgiunti!");
		}

		/* se gli insiemi A e C non sono disgiunti, stampa gli elementi comuni */

		if (!Collections.disjoint(a, c)) {
			a.retainAll(c);
			System.out.println("Gli insiemi A e C hanno elementi comuni: " + a);
		}
	}
}

