/* file Esercizio15.java */

import java.util.List;
import java.util.stream.Stream;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Esercizio15 {
	public static void main(String [] args) {
		List<Integer> li = IntStream.rangeClosed(1, 10).boxed().collect(Collectors.toList());

		String s = li.stream().map(Object::toString).collect(Collectors.joining(", "));
		System.out.println(s);
	}
}

