/* file Esercizio26.java */

import java.util.SortedSet;
import java.util.TreeSet;

public class Esercizio26 {
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

		TreeSet<Integer> s_diff = new TreeSet<Integer>(a);
		TreeSet<Integer> s_int = new TreeSet<Integer>(a);

		// calcola l'unione A + B
		s_diff.addAll(b);

		// calcola l'intersezione A & B
		s_int.retainAll(b);

		// calcola la differenza simmetrica A ^ B  = (A + B) - (A & B)
		s_diff.removeAll(s_int);

		s_int = new TreeSet<Integer>(s_diff);
		
		// calcola l'unione (A ^ B) + C
		s_diff.addAll(c);

		// calcola l'intersezione (A ^ B) & C
		s_int.retainAll(c);

		// calcola la differenza simmetrica A ^ B ^ C  = ((A ^ B) + C) - ((A ^ B) & C)
		s_diff.removeAll(s_int);

		System.out.println("Differenza simmetrica tra gli insiemi A, B e C: " + s_diff);
	}
}

