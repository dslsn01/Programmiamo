/* file Esercizio20.java */

import java.util.Set;
import java.util.HashSet;
import java.util.Collections;

public class Esercizio20 {
	public static void main(String [] args) {
		/* l'insieme A non è ordinato */

		Set<Integer> a = new HashSet<Integer>();

		a.add(4);
		a.add(6);
		a.add(0);
		a.add(2);
		a.add(5);
		a.add(7);
		a.add(1);
		a.add(3);

		System.out.println("A = " + a);

		/* stampa la cardinalità di A */

		System.out.println("Cardinalità dell'insieme A: " + a.size());

		/* poichè l'HashSet non è ordinato, cerchiamo il suo massimo e minimo */

		System.out.println("Elemento minore dell'insieme A: " + Collections.min(a));
		System.out.println("Elemento maggiore dell'insieme A: " + Collections.max(a));
	}
}

