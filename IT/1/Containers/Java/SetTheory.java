/* file SetTheory.java */

import java.util.SortedSet;
import java.util.TreeSet;

public class SetTheory {
	public static void main(String [] args) {
		/* dichiara due Set di numeri interi */

		SortedSet<Integer> a = new TreeSet<Integer>();

		a.add(0);
		a.add(1);
		a.add(2);

		SortedSet<Integer> b = new TreeSet<Integer>();

		b.add(2);
		b.add(3);
		b.add(4);

		System.out.println("A = " + a);
		System.out.println("B = " + b);

		/* unione di A e B */

		SortedSet<Integer> s_union = new TreeSet<Integer>(a);
		s_union.addAll(b);

		System.out.println("A u B = " + s_union);

		/* intersezione di A e B */

		SortedSet<Integer> intersection = new TreeSet<Integer>(a);
		intersection.retainAll(b);

		System.out.println("A & B = " + intersection);

		/* differenza tra A e B */

		SortedSet<Integer> diff = new TreeSet<Integer>(a);
		diff.removeAll(b);
		System.out.println("A - B = " + diff);

		/* ...e differenza tra B e A */

		diff = new TreeSet<Integer>(b);
		diff.removeAll(a);
		System.out.println("B - A = " + diff);

		/* differenza simmetrica tra A e B */

		SortedSet<Integer> s_diff = new TreeSet<Integer>(a);

		/* calcola l'unione A u B */

		s_diff.addAll(b);

		/* calcola la differenza simmetrica A ^ B  = (A u B) - (A & B) */

		s_diff.removeAll(intersection);

		System.out.println("A ^ B = " + s_diff);
	}
}

