/* file Esercizio5.java */

import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Esercizio5 {
	public static void main(String [] args) {
		List<Integer> li = new Random().ints(10, 1, 10).boxed().collect(Collectors.toList());
		System.out.println(li);

		List<Integer> u = li.stream().distinct().collect(Collectors.toList());
		System.out.println(u);
	}
}

