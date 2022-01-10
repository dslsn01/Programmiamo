/* file Esercizio6.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Esercizio6 {
	public static void main(String [] args) {
		List<Integer> li = IntStream.rangeClosed(1, 10).boxed().collect(Collectors.toList());
		System.out.println(li);

		List<Integer> u = li.stream().map(n -> n * 2).collect(Collectors.toList());
		System.out.println(u);
	}
}

