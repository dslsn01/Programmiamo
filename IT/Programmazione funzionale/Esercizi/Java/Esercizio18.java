/* file Esercizio18.java */

import java.util.Locale;
import java.util.List;
import java.util.Random;
import java.util.stream.DoubleStream;
import java.util.stream.Collectors;
// import java.util.function.Function;

public class Esercizio18 {
	private static double mdn(List<Integer> li) {
		DoubleStream stream = li.stream().mapToDouble(/*Function::identity*/i -> i).sorted();

		return li.size() % 2 != 0 ? 
			   stream.skip(li.size()/2).findFirst().getAsDouble() : 
			   stream.skip(li.size()/2-1).limit(2).average().getAsDouble();
	}

	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> li = rand.ints(rand.nextInt(100) + 1, 1, 100).boxed().collect(Collectors.toList());

		double m = mdn(li);

		System.out.println(li);
		System.out.println("Mediana: " + String.format(Locale.ROOT, "%.2f", m) + ".");
	}
}

