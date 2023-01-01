/* file Esercizio7.java */

public class Esercizio7 {
	static int maximum(int a, int b) {
		return a > b ? a : b;
	}

	public static void main(String [] args) {
		int a = 5;
		int b = 10;
		int c = 15;

		System.out.println("Massimo tra " + a + " e " + b + ": " + maximum(a, b));
		System.out.println("Massimo tra " + b + " e " + c + ": " + maximum(b, c));
	}
}

