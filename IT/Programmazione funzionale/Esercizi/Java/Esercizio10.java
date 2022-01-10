/* file Esercizio10.java */

import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Esercizio10 {
	public static void main(String [] args) {
		List<Integer> e = IntStream.rangeClosed(1, 100).filter(n -> n % 2 == 0).boxed().collect(Collectors.toList());
		System.out.println(e);
	}
}

