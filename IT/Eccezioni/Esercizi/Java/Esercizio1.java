/* file Esercizio1.java */

public class Esercizio1 {
	public static void main(String [] args) {
		String [] arr = {"rosso", "verde", "blu"};

		int i = 0;

		while (true) {
			try {
				System.out.println(arr[i]);
				i++;
			}
			catch (ArrayIndexOutOfBoundsException e) {
				break;
			}
		}

		System.out.println("Fine del programma.");
	}
}

