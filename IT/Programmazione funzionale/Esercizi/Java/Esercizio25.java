/* file Esercizio25.java */

import java.util.function.Function;

public class Esercizio25 {
	public static void main(String [] args) {
		Function<Integer, Function<Integer, Integer>> f = a -> b -> a + b;

		System.out.println("3 + 3 = " + f.apply(3).apply(3));

		Function<Integer, Integer> g = f.apply(0);

		System.out.println("id(3) = " + g.apply(3));

		Function<Integer, Function<Integer, Integer>> h = a -> b -> a - b;

		System.out.println("3 - 2 = " + h.apply(3).apply(2));

		// calcola l'elemento inverso

		Function<Integer, Integer> i = h.apply(0);

		System.out.println("Inverso additivo di 3 = " + i.apply(3));
	}
}

