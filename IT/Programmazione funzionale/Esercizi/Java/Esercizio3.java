/* file Esercizio3.java */

import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Esercizio3 {
	public static void main(String [] args) {
		Random rand = new Random();
		List<Integer> li = rand.ints(10, 1, 10).boxed().collect(Collectors.toList());
		System.out.println(li);
	}
}

