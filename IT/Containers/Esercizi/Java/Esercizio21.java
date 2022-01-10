/* file Esercizio21.java */

import java.util.Set;
import java.util.HashSet;

public class Esercizio21 {
	public static void main(String [] args) {
		/* gli insiemi A e B non sono ordinati */

		Set<Integer> a = new HashSet<Integer>();

		a.add(1);
		a.add(2);
		a.add(3);

		Set<Integer> b = new HashSet<Integer>();

		b.add(3);
		b.add(2);
		b.add(1);

		System.out.println("A = " + a);
		System.out.println("B = " + b);

		/* verifica se A e B siano uguali */

		System.out.println("Gli insiemi A e B sono uguali? " + a.equals(b));
	}
}

