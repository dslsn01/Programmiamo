/* file Currying.java */

import java.util.Locale;
import java.util.function.Function;

public class Currying {
	public static void main(String [] args) {
		// funzione che calcola la percentuale, ad es. il 30% di 100
		Function<Integer, Function<Integer, Double>> percent = x -> y -> (double) x / 100 * y;

		// calcola il 60% di 120: invoca la funzione con entrambi i parametri
		System.out.println("60% di 120 = " + percent.apply(120).apply(60));

		// applicazione parziale della funzione: fissa il primo parametro al variare del secondo
		Function<Integer, Double> part = percent.apply(70);

		System.out.println("30% di 70 = " + part.apply(30));
		System.out.println("60% di 70 = " + part.apply(60));
		System.out.println("90% di 70 = " + String.format(Locale.ROOT, "%.1f", part.apply(90)));
	}
}

