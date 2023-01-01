/* file Esercizio17.java */

import java.util.Locale;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Esercizio17 {
	private static double avg(List<Integer> li) {
		return (double) li.stream().reduce(0, (m, n) -> m + n) / (double) li.size();
	}

	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> li = rand.ints(25, 1, 100).boxed().collect(Collectors.toList());

		double m = avg(li);

		System.out.println(li);
		System.out.println("Media: " + String.format(Locale.ROOT, "%.2f", m) + ".");
	}
}

