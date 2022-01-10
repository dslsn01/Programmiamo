/* file Esercizio3.java */

public class Esercizio3 {
	public static void main(String [] args) {
		int a = 5;
		double b = 2.5;

		System.out.println("a = " + a + ", b = " + b);

		double c = a + b;
		/* conversione possibile del risultato a intero, ma perdendo la parte decimale */
		int d = (int)(a + b);

		System.out.println("a + b (risultato double) = " + c);
		System.out.println("a + b (convertito a intero) = " + d);
	}
}

