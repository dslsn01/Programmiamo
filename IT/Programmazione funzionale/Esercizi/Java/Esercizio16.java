/* file Esercizio16.java */

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class Esercizio16 {
	public static void main(String [] args) {
		Integer [] l1 = {1, 2, 3, 4};
		Integer [] l2 = {5, 6, 7};
		Integer [] l3 = {8, 9};
		Integer [] l4 = {10};

		Integer [][] li = new Integer[][]{l1, l2, l3, l4};

		List<Integer> flat = Stream.of(li).flatMap(Stream::of).collect(Collectors.toList());

		Stream.of(li).map(Arrays::toString).forEach(System.out::print);
		System.out.print(System.lineSeparator());

		System.out.println(flat);
	}
}

