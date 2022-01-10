/* file Esercizio1.java */

public class Esercizio1 {
	static int id(int n) {
		return n;
	}

	public static void main(String [] args) {
		for (int i = 1; i <= 3; i++) {
			System.out.println("id(" + i + ") = " + id(i) + " ");
		}
	}
}

