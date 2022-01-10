/* file Esercizio9.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Esercizio9 {
	public static void main(String [] args) {
		List<Integer> m = IntStream.rangeClosed(1, 100).map(n -> n * 6).boxed().collect(Collectors.toList());
		System.out.println(m);
	}
}

