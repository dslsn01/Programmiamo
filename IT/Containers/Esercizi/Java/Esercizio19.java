/* file Esercizio19.java */

import java.util.SortedSet;
import java.util.TreeSet;

public class Esercizio19 {
	public static void main(String [] args) {
		SortedSet<Integer> a = new TreeSet<Integer>();

		a.add(0);
		a.add(1);
		a.add(2);
		a.add(3);
		a.add(4);
		a.add(5);
		a.add(6);
		a.add(7);

		System.out.println("A = " + a);

		/* stampa la cardinalità di A, il suo massimo e minimo */

		System.out.println("Cardinalità dell'insieme A: " + a.size());
		System.out.println("Elemento minore dell'insieme A: " + a.first());
		System.out.println("Elemento maggiore dell'insieme A: " + a.last());
	}
}

