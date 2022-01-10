/* file Esercizio24.java */

import java.util.SortedSet;
import java.util.TreeSet;

public class Esercizio24 {
	public static void main(String [] args) {
		SortedSet<Integer> a = new TreeSet<Integer>();

		a.add(1);
		a.add(2);
		a.add(3);

		SortedSet<Integer> b = new TreeSet<Integer>();

		b.add(3);
		b.add(4);
		b.add(5);

		SortedSet<Integer> c = new TreeSet<Integer>();

		c.add(-1);
		c.add(0);
		c.add(1);

		System.out.println("A = " + a);
		System.out.println("B = " + b);
		System.out.println("C = " + c);

		/* calcola la differenza tra A e B: tutti gli elementi di A non presenti in B */

		a.removeAll(b);
		System.out.println("Differenza tra A e B: " + a);

		/* calcola la differenza tra (A - B) e C: tutti gli elementi di A non presenti in B nè in C */

		a.removeAll(c);
		System.out.println("Differenza tra (A - B) e C: " + a);
	}
}

