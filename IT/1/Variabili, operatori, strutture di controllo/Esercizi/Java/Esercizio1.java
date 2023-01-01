/* file Esercizio1.java */

public class Esercizio1 {
	public static void main(String [] args) {
		int a = 5;
		int b = 10;

		System.out.println("a = " + a + ", b = " + b);

		int c = a + b;
		a = a + b;

		System.out.println("a = " + a);
		System.out.println("b = " + b);
		System.out.println("c = " + c);
	}
}

