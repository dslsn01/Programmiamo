/* file Esercizio25.java */

import java.util.SortedSet;
import java.util.TreeSet;

public class Esercizio25 {
	public static void main(String [] args) {
		SortedSet<Integer> a = new TreeSet<Integer>();

		a.add(1);
		a.add(2);
		a.add(3);

		SortedSet<Integer> b = new TreeSet<Integer>();

		b.add(2);
		b.add(3);
		b.add(4);

		SortedSet<Integer> c = new TreeSet<Integer>();

		c.add(3);
		c.add(4);
		c.add(5);

		System.out.println("A = " + a);
		System.out.println("B = " + b);
		System.out.println("C = " + c);

		SortedSet<Integer> intersection = new TreeSet<Integer>(a);
		intersection.retainAll(b);
		intersection.retainAll(c);

		System.out.println("Intersezione tra gli insiemi A, B e C: " + intersection);
	}
}

