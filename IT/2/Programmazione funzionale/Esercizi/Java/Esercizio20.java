/* file Esercizio20.java */

import java.util.function.Function;
import java.util.function.BiFunction;

public class Esercizio20 {
	public static void main(String [] args) {
		Function<Integer, Integer> s = n -> n + 1;
		BiFunction<Function<Integer, Integer>, Integer, Integer> ff = (f, n) -> f.apply(f.apply(n));

		System.out.println("Successore del successore di zero: " + ff.apply(s, 0));
	}
}

