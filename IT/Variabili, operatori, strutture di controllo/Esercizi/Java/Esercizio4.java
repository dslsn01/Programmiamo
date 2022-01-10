/* file Esercizio4.java */

public class Esercizio4 {
	public static void main(String [] args) {
		int a = 5;
		int b = 10;

		System.out.println("a = " + a + ", b = " + b);

		int s = a + b;

		System.out.println(a  + " + " + b + " = " + s);

		int d = a - b;

		if (d < 0) {
			System.out.println("Differenza negativa!");
		}

		System.out.println(a  + " - " + b + " = " + d);

		if (d != b-a) {
			System.out.println("Sottrazione non commutativa. Scambio gli operandi.");
			d = b - a;
			System.out.println(b  + " - " + a + " = " + d);
		}

		int p = a * b;

		System.out.println(a  + " * " + b + " = " + p);

		double q = (double)a / b;

		System.out.println(a  + " / " + b + " = " + q);

		if (q != (double)b/a) {
			System.out.println("Divisione non commutativa. Scambio gli operandi.");
			q = (double)b / a;
			System.out.println(b  + " / " + a + " = " + q);
		}
	}
}

