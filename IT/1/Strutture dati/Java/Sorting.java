/* file Sorting.java */

import java.util.Arrays;
import java.util.Random;

public class Sorting {
	public static void main(String [] args) {
		/* dichiara un array di interi casuali */

		int [] arr = new int[10];

		Random rand = new Random();

		for (int i = 0; i < arr.length; i++) {
			arr[i] = rand.nextInt(100) + 1;
		}

		System.out.println("Array originale:");
		System.out.println(Arrays.toString(arr));

		/* ordina gli elementi dell'array */

		Arrays.sort(arr);

		System.out.println("Array ordinato:");
		System.out.println(Arrays.toString(arr));
	}
}

