/* file Esercizio21.java */

import java.util.Arrays;

public class Esercizio21 {
	static void square(int [] arr) {
		for (int i = 0; i < arr.length; i++) {
			arr[i] *= arr[i];
		}
	}

	public static void main(String [] args) {
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		System.out.println("Array originale: ");
		System.out.println(Arrays.toString(arr));

		square(arr);

		System.out.println("Array (elementi al quadrato): ");
		System.out.println(Arrays.toString(arr));
	}
}

