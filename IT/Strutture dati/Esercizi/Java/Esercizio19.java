/* file Esercizio19.java */

import java.util.Arrays;

public class Esercizio19 {
	public static void main(String [] args) {
		int [] a = new int[10];

		for (int i = 0, j = 2; i < a.length; i++, j += 2) {
			if (j % 2 == 0) {
				a[i] = j;
			}
		}

		int [] b = new int[10];

		for (int i = 0, j = 3; i < b.length; i++, j += 3) {
			if (j % 3 == 0) {
				b[i] = j;
			}
		}

		System.out.println(Arrays.toString(a));
		System.out.println(Arrays.toString(b));

		System.out.print("Elementi comuni: ");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				if (a[i] == b[j]) {
					System.out.print(a[i] + " ");
				}
			}
		}

		System.out.print(System.lineSeparator());
	}
}

