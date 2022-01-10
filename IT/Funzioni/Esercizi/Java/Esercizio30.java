/* file Esercizio30.java */

import java.io.Console;
import java.util.function.IntBinaryOperator;
import java.util.function.BiFunction;
import java.util.Locale;

public class Esercizio30 {
	public static void main(String [] args) {
		Console console = System.console();
		// somma

		IntBinaryOperator add = (n1, n2) -> n1 + n2;

		// sottrazione
		IntBinaryOperator subtr = (n1, n2) -> n1 - n2;

		// prodotto
		IntBinaryOperator mult = (n1, n2) -> n1 * n2;

		// divisione
		BiFunction<Integer, Integer, Float> divide = (n1, n2) -> n2 != 0 ? (float) n1 / n2 : Float.NaN;

		String o1 = "?";
		String o2 = o1;

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

		int n1 = Integer.parseInt(o1);
		int n2 = Integer.parseInt(o2);

		String op = System.console().readLine("Scegli un'operazione:\n+ - somma,\n- - sottrazione,\n* - prodotto,\n/ - divisione\n");

		if (op.equals("+")) {
			System.out.println(n1 + " + " + n2 + " = " + add.applyAsInt(n1, n2));
		}

		if (op.equals("-")) {
			System.out.println(n1 + " - " + n2 + " = " + subtr.applyAsInt(n1, n2));
		}

		if (op.equals("*")) {
			System.out.println(n1 + " * " + n2 + " = " + mult.applyAsInt(n1, n2));
		}

		if (op.equals("/")) {
			System.out.println(n1 + " / " + n2 + " = " + String.format(Locale.ROOT, "%.3f", divide.apply(n1, n2)));
		}
	}
}

