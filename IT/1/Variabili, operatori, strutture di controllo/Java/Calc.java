/* file Calc.java */

import java.io.Console;
import java.util.Locale;

public class Calc {
	public static void main(String [] args) {
		// legge due numeri da tastiera
		Console console = System.console();

		String o1 = "?";
		String o2 = o1;

		// valida gli operandi

		while (!o1.matches("[+-]?[\\d]+")) {
			if (o1.isEmpty()) System.out.println("Stringa vuota!");
			else if (!o1.equals("?")) System.out.println("Numero \"" + o1 + "\" non valido!");
			o1 = console.readLine("Primo operando: ");
		}

		while (!o2.matches("[+-]?[\\d]+")) {
			if (o2.isEmpty()) System.out.println("Stringa vuota!");
			else if (!o2.equals("?")) System.out.println("Numero \"" + o2 + "\" non valido!");
			o2 = console.readLine("Secondo operando: ");
		}

		// converte gli operandi in numeri

		int n1 = Integer.parseInt(o1);
		int n2 = Integer.parseInt(o2);

		// legge l'operazione scelta

		System.out.println("Scegli un'operazione:\n+ - somma,\n- - sottrazione,\n* - prodotto,\n/ - divisione");

		String op = console.readLine();

		int result = 0;

		// esegue la somma

		if (op.equals("+")) {
			result = n1 + n2;
			System.out.println(n1 + " + " + n2 + " = " + result);
		}

		// esegue la sottrazione

		if (op.equals("-")) {
			result = n1 - n2;
			System.out.println(n1 + " - " + n2 + " = " + result);
		}

		// esegue la moltiplicazione

		if (op.equals("*")) {
			result = n1 * n2;
			System.out.println(n1 + " * " + n2 + " = " + result);
		}

		// esegue la divisione

		if (op.equals("/")) {
			if (n2 == 0) {
				System.out.println("Impossibile eseguire la divisione per zero!");
			}
			else
			{
				// stampa tre cifre decimali al massimo
				double q = (double) n1 / n2;
				System.out.println(n1 + " / " + n2 + " = " + String.format(Locale.ROOT, "%.3f", q));
			}
		}
	}
}

