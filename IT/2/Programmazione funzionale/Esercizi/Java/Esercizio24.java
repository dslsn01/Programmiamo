/* file Esercizio24.java */

import java.util.Locale;
import java.util.function.Function;

public class Esercizio24 {
	public static void main(String [] args) {
		Function<Integer, Function<Integer, Integer>> f = a -> b -> a * b;

		System.out.println("3 x 3 = " + f.apply(3).apply(3));

		Function<Integer, Integer> g = f.apply(1);

		System.out.println("id(3) = " + g.apply(3));

		Function<Integer, Function<Integer, Double>> h = a -> b -> (double) a / b;

		System.out.println("3 / 2 = " + h.apply(3).apply(2));

		// calcola l'elemento inverso

		Function<Integer, Double> i = h.apply(1);

		System.out.println("Inverso moltiplicativo di 3 = " + String.format(Locale.ROOT, "%.6f", i.apply(3)));
	}
}

