/* file Esercizio13.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Esercizio13 {
	public static void main(String [] args) {
		List<Integer> li = IntStream.rangeClosed(1, 100).boxed().collect(Collectors.toList());

		int tot = li.stream().reduce(0, (a, b) -> a + b);

		System.out.println(li);
		System.out.println("Somma dei numeri in lista: " + tot);
	}
}

