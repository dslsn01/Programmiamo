/* file Esercizio28.java */

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Esercizio28 {
	private static int rsum(List<Integer> li) {
		if (li.isEmpty()) return 0;
		else {
			return li.get(0) + rsum(li.subList(1, li.size()));
		}
	}

	public static void main(String [] args) {
		List<Integer> li = IntStream.rangeClosed(1, 100).boxed().collect(Collectors.toList());
		System.out.println("Somma dei numeri da 1 a 100 = " + rsum(li));
	}
}

