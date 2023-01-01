/* file Esercizio19.java */

import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.stream.Stream;
import java.util.stream.Collectors;
import java.util.function.Function;

public class Esercizio19 {
	private static List<Map.Entry<Integer, Long>> mode(List<Integer> li) {
		final Map<Integer, Long> m = li.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
		final long md = m.values().stream().mapToLong(count -> count).max().orElse(-1);
		return m.entrySet().stream().filter(t -> t.getValue() == md)
		.collect(Collectors.toList());
	}

	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> li = rand.ints(rand.nextInt(100) + 1, 1, 100).boxed().collect(Collectors.toList());

		System.out.println(li);

		// valori con relativa frequenza

		List<Map.Entry<Integer, Long>> fv = mode(li);

		Long md = fv.get(0).getValue();

		if (md == 1) {
			System.out.println("La lista non ha una moda.");
			return;
		}

		// stampa la moda

		System.out.print("Moda (" + md + " occorrenze): ");

		System.out.println(fv.stream().map(t -> t.getKey()).map(Object::toString).collect(Collectors.joining(", ")));
	}
}

