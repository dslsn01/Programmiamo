/* file Esercizio4.java */

import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Esercizio4 {
	public static void main(String [] args) {
		List<Integer> li = new Random().ints(10, 1, 100).boxed().collect(Collectors.toList());
		System.out.println(li);

		List<Integer> l2 = li.stream().sorted().collect(Collectors.toList());
		System.out.println(l2);

		List<Integer> l3 = li.stream().sorted(Collections.reverseOrder()).collect(Collectors.toList());
		System.out.println(l3);
	}
}

