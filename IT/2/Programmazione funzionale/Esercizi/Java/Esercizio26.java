/* file Esercizio26.java */

import java.util.Random;
import java.util.function.Function;

public class Esercizio26 {
	public static void main(String [] args) {
		Random rand = new Random();
		int a = rand.nextInt(10)+1;
		int b = rand.nextInt(10)+1;
		int c = rand.nextInt(10)+1;

		System.out.println("a=" + a + ", b=" + b + ", c=" + c);

		Function<Integer, 
			Function<Integer, 
				Function<Integer, Integer>>> f = x -> y -> z -> {
					if (x > b) {
						return x > z ? x : z;
					}
					else {
						return y > z ? y : z;
					}
		};

		System.out.println("Trovo il maggiore con l'applicazione parziale: ");

		// h = f(a, ...)

		Function<Integer, Function<Integer, Integer>> h = f.apply(a);

		System.out.println("Numero maggiore: " + h.apply(b).apply(c));

		// i = f(a, b, ...)

		Function<Integer, Integer> i = h.apply(b);

		System.out.println("Numero maggiore: " + i.apply(c));

		System.out.println("Trovo il maggiore con il currying: ");

		int m = f.apply(a).apply(b).apply(c);

		System.out.println("Numero maggiore: " + m);
	}
}

