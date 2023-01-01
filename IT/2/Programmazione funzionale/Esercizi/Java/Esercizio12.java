/* file Esercizio12.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Esercizio12 {
	public static void main(String [] args) {
		// trova tutti i numeri dispari che sono anche multipli di 3

		List<Integer> m = IntStream.rangeClosed(1, 100).filter(n -> n % 3 == 0).boxed().filter(n -> n % 2 == 1).collect(Collectors.toList());
		System.out.println(m);
	}
}

