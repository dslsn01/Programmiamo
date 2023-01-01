/* file Esercizio21.java */

import java.util.Locale;
import java.util.function.Function;

public class Esercizio21 {
	public static void main(String [] args) {
		Function<Double, Double> f = (x) -> Math.pow(Math.E, x);
		Function<Double, Double> g = (y) -> y + 1;

		// funzione composta (g o f)(x) = e^x + 1
		Function<Double, Double> gof = g.compose(f);

		System.out.println("e^3 + 1 = " + String.format(Locale.ROOT, "%.4f", gof.apply(3.0)));
	}
}

