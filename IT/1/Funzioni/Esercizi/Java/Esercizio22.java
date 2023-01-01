/* file Esercizio22.java */

import java.util.Arrays;

public class Esercizio22 {
	static void swap(int [] arr) {
		for (int i = 0, j = arr.length-1; i < arr.length / 2; i++, j--) {
			int z = arr[j];
			arr[j] = arr[i];
			arr[i] = z;
		}
	}

	public static void main(String [] args) {
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		System.out.println("Array originale: ");
		System.out.println(Arrays.toString(arr));

		swap(arr);

		System.out.println("Array (elementi invertiti): ");
		System.out.println(Arrays.toString(arr));
	}
}

