/* file TestArray2.java */

import java.util.Arrays;

public class TestArray2 {
	public static void main(String [] args) {
		/* crea un array di caratteri */

		char [] arr1 = {'C', 'i', 'a', 'o', ',', ' '};

		System.out.println(Arrays.toString(arr1));

		/* sezione di array */

		char [] sect1 = Arrays.copyOfRange(arr1, 0, 3);
		char [] sect2 = Arrays.copyOfRange(arr1, 3, arr1.length);
		char [] sect3 = Arrays.copyOfRange(arr1, 1, 4);
		
		System.out.println(Arrays.toString(sect1));
		System.out.println(Arrays.toString(sect2));
		System.out.println(Arrays.toString(sect3));

		/* crea un secondo array */

		char [] arr2 = new char[6];

		arr2[0] = 'm';
		arr2[1] = 'o';
		arr2[2] = 'n';
		arr2[3] = 'd';
		arr2[4] = 'o';
		arr2[5] = '!';

		System.out.println(Arrays.toString(arr2));

		/* concatena i due array */

		int size1 = arr1.length;
		int size2 = arr2.length;
		char [] arr3 = new char[size1 + size2];

		System.arraycopy(arr1, 0, arr3, 0, size1);
		System.arraycopy(arr2, 0, arr3, size1, size2);

		System.out.println(Arrays.toString(arr3));
	}
}

