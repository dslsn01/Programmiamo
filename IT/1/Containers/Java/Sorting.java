/* file Sorting.java */

import java.util.Random;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Sorting {
	public static void main(String [] args) {
		/* dichiara una lista di interi casuali */

		List <Integer> arr = new ArrayList<Integer>();

		Random rand = new Random();

		for (int i = 0; i < 10; i++) {
			int n = rand.nextInt(100) + 1;
			arr.add(n);
		}

		System.out.println("Lista originale:");
		System.out.println(arr);

		/* ordina gli elementi dell'array */

		Collections.sort(arr);

		System.out.println("Lista ordinata:");
		System.out.println(arr);
	}
}

