/* file Esercizio17.java */

import java.io.Console;

public class Esercizio17 {
	public static double divide(int a, int b) {
		if (b == 0) {
			if (a == 0) {
				throw new IllegalArgumentException("Operazione non definita!");
			} else {
				throw new ArithmeticException("Divisione per zero!");
			}
		}

		return (double)a / b;
	}

	public static void main(String [] args) {
		System.out.println("Divisione tra numeri interi");
		Console console = System.console();

		try {
			int a = Integer.parseInt(console.readLine("Dividendo: "));
			int b = Integer.parseInt(console.readLine("Divisore: "));

			double result = divide(a, b);

			System.out.println(a + " / " + b + " = " + result);
		}
		catch (NumberFormatException e) {
			System.out.println(e.getMessage());
		}
		catch (ArithmeticException e) {
			System.out.println(e.getMessage());
		}
		catch (IllegalArgumentException e) {
			System.out.println(e.getMessage());
		}

		System.out.println("Fine del programma.");
	}
}

