/* file PassByReference.java */

public class PassByReference {
	static void resetArray(int [] arr) {
		for (int i = 0; i < arr.length; i++) {
			arr[i] = 0;
		}
	}

	public static void main(String [] args) {
		int arr[] = {1, 2, 3};

		for (int n : arr) {
			System.out.print(n + " ");
		}

		System.out.print(System.lineSeparator());

		resetArray(arr);

		for (int n : arr) {
			System.out.print(n + " ");
		}

		System.out.print(System.lineSeparator());
	}
}

